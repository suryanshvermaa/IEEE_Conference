import { Mail, Globe, Linkedin } from 'lucide-react'

export default function Footer() {
  const currentYear = new Date().getFullYear()

  return (
    <footer className="bg-ieee-dark border-t border-slate-800">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-12">
        <div className="grid grid-cols-1 md:grid-cols-3 gap-10">
          {/* Brand */}
          <div>
            <div className="flex items-center gap-3 mb-4">
              <div className="flex items-center justify-center w-10 h-10 rounded-lg bg-ieee-blue border border-blue-500/40">
                <span className="text-white font-extrabold text-sm">IAS</span>
              </div>
              <div>
                <p className="text-white font-bold text-sm">IEEE IAS SBC</p>
                <p className="text-slate-400 text-xs">NIT Patna</p>
              </div>
            </div>
            <p className="text-slate-400 text-sm leading-relaxed">
              Bridging academia and industry through innovation, research, and global professional engagement.
            </p>
          </div>

          {/* Quick Links */}
          <div>
            <h4 className="text-white font-semibold mb-4 text-sm uppercase tracking-widest">Quick Links</h4>
            <ul className="flex flex-col gap-2">
              {['About', 'Why Join', 'Chapter', 'Membership', 'Vision'].map((item) => (
                <li key={item}>
                  <a
                    href={`#${item.toLowerCase().replace(' ', '-')}`}
                    className="text-slate-400 hover:text-white text-sm transition-colors"
                  >
                    {item}
                  </a>
                </li>
              ))}
            </ul>
          </div>

          {/* Contact */}
          <div>
            <h4 className="text-white font-semibold mb-4 text-sm uppercase tracking-widest">Connect</h4>
            <ul className="flex flex-col gap-3">
              <li>
                <a
                  href="mailto:ieee.ias@nitp.ac.in"
                  className="flex items-center gap-2 text-slate-400 hover:text-white text-sm transition-colors"
                >
                  <Mail size={14} />
                  ieee.ias@nitp.ac.in
                </a>
              </li>
              <li>
                <a
                  href="https://www.nitp.ac.in"
                  target="_blank"
                  rel="noopener noreferrer"
                  className="flex items-center gap-2 text-slate-400 hover:text-white text-sm transition-colors"
                >
                  <Globe size={14} />
                  nitp.ac.in
                </a>
              </li>
              <li>
                <a
                  href="https://www.linkedin.com/company/ieee-ias-nitp"
                  target="_blank"
                  rel="noopener noreferrer"
                  className="flex items-center gap-2 text-slate-400 hover:text-white text-sm transition-colors"
                >
                  <Linkedin size={14} />
                  LinkedIn
                </a>
              </li>
            </ul>
          </div>
        </div>

        <div className="mt-10 pt-6 border-t border-slate-800 flex flex-col sm:flex-row items-center justify-between gap-3">
          <p className="text-slate-500 text-sm">
            &copy; {currentYear} IEEE IAS Student Branch Chapter, NIT Patna. All rights reserved.
          </p>
          <p className="text-slate-500 text-xs">
            IEEE Region 10 &bull; IEEE Kolkata Section
          </p>
        </div>
      </div>
    </footer>
  )
}
