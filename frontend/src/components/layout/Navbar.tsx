import { useState, useEffect } from 'react'
import { Menu, X } from 'lucide-react'
import { NAV_LINKS } from '@/constants'

export default function Navbar() {
  const [isOpen, setIsOpen] = useState(false)
  const [scrolled, setScrolled] = useState(false)

  useEffect(() => {
    const handleScroll = () => setScrolled(window.scrollY > 20)
    window.addEventListener('scroll', handleScroll)
    return () => window.removeEventListener('scroll', handleScroll)
  }, [])

  return (
    <header
      className={`fixed top-0 left-0 right-0 z-50 transition-all duration-300 ${
        scrolled
          ? 'bg-white/95 backdrop-blur-xl border-b border-slate-200 shadow-sm'
          : 'bg-white/80 backdrop-blur-md border-b border-slate-100'
      }`}
    >
      <nav className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div className="flex items-center justify-between h-16 md:h-20">
          {/* Logo */}
          <a href="#home" className="flex items-center gap-3 group">
            <div className="flex items-center justify-center w-10 h-10 rounded-lg bg-ieee-navy border-0 group-hover:bg-ieee-blue transition-colors duration-200">
              <span className="text-white font-extrabold text-sm leading-none">IAS</span>
            </div>
            <div className="hidden sm:block">
              <p className="text-slate-800 font-bold text-sm leading-tight">IEEE IAS SBC</p>
              <p className="text-slate-500 text-xs">NIT Patna</p>
            </div>
          </a>

          {/* Desktop links */}
          <ul className="hidden md:flex items-center gap-1">
            {NAV_LINKS.map((link) => (
              <li key={link.label}>
                <a
                  href={link.href}
                  className="px-3 py-2 text-sm text-slate-600 hover:text-ieee-blue rounded-md transition-colors duration-150 font-medium"
                >
                  {link.label}
                </a>
              </li>
            ))}
          </ul>

          {/* CTA */}
          <div className="hidden md:flex items-center gap-3">
            <a
              href="#membership"
              className="px-5 py-2.5 rounded-lg bg-ieee-blue text-white font-semibold text-sm hover:bg-ieee-navy transition-colors duration-200 shadow-sm"
            >
              Join Now
            </a>
          </div>

          {/* Mobile burger */}
          <button
            onClick={() => setIsOpen(!isOpen)}
            className="md:hidden p-2 rounded-lg text-slate-600 hover:text-slate-900 hover:bg-slate-100 transition-colors"
            aria-label="Toggle menu"
          >
            {isOpen ? <X size={22} /> : <Menu size={22} />}
          </button>
        </div>
      </nav>

      {/* Mobile drawer */}
      {isOpen && (
        <div className="md:hidden bg-white border-t border-slate-200 shadow-lg">
          <ul className="flex flex-col px-4 py-4 gap-1">
            {NAV_LINKS.map((link) => (
              <li key={link.label}>
                <a
                  href={link.href}
                  onClick={() => setIsOpen(false)}
                  className="block px-4 py-3 text-slate-600 hover:text-ieee-blue rounded-lg hover:bg-blue-50 transition-colors duration-150 font-medium"
                >
                  {link.label}
                </a>
              </li>
            ))}
            <li className="mt-3">
              <a
                href="#membership"
                onClick={() => setIsOpen(false)}
                className="block text-center px-4 py-3 rounded-lg bg-ieee-blue text-white font-semibold hover:bg-ieee-navy transition-colors"
              >
                Join Now
              </a>
            </li>
          </ul>
        </div>
      )}
    </header>
  )
}
