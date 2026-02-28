import { Star, ArrowRight } from 'lucide-react'
import SectionHeader from '@/components/ui/SectionHeader'
import { MEMBERSHIP_OPTIONS } from '@/constants'
import Button from '@/components/ui/Button'

export default function Membership() {
  return (
    <section id="membership" className="py-28 bg-ieee-subtle section-muted">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <SectionHeader
          badge="Membership"
          title="Join IEEE"
          highlight="IAS Today"
          subtitle="Flexible membership options designed for students, professionals, and organizations looking to advance their careers and industry impact."
        />

        <div className="grid grid-cols-1 md:grid-cols-3 gap-8">
          {MEMBERSHIP_OPTIONS.map((option) => (
            <div
              key={option.title}
              className={`relative flex flex-col rounded-2xl p-8 border transition-all duration-300 hover:-translate-y-1 ${
                option.highlight
                  ? 'bg-gradient-to-b from-ieee-navy to-ieee-blue text-white border-ieee-blue shadow-xl shadow-blue-700/20'
                  : 'bg-white border-slate-200 hover:border-blue-300 shadow-sm hover:shadow-md'
              }`}
            >
              {option.highlight && (
                <div className="absolute -top-4 left-1/2 -translate-x-1/2">
                  <span className="flex items-center gap-1.5 px-4 py-1.5 rounded-full bg-ieee-blue text-white text-xs font-bold uppercase tracking-wide shadow-md">
                    <Star size={12} fill="currentColor" />
                    Most Popular
                  </span>
                </div>
              )}

              <h3
                className={`text-xl font-bold mb-4 ${
                  option.highlight ? 'text-white' : 'text-slate-800'
                }`}
              >
                {option.title}
              </h3>

              <div
                className={`h-px w-full mb-6 ${
                  option.highlight ? 'bg-blue-500/40' : 'bg-slate-200'
                }`}
              />

              <p className={`text-sm leading-relaxed flex-1 mb-8 ${
                option.highlight ? 'text-blue-100' : 'text-slate-500'
              }`}>
                {option.description}
              </p>

              <Button
                as="a"
                href="https://www.ieee.org/membership/join/index.html"
                variant={option.highlight ? 'secondary' : 'outline'}
                size="md"
                className="w-full"
              >
                Get Started
                <ArrowRight size={16} />
              </Button>
            </div>
          ))}
        </div>

        <p className="text-center text-slate-400 text-sm mt-10">
          Students receive significantly reduced membership dues •{' '}
          <a
            href="https://www.ieee.org/membership/index.html"
            target="_blank"
            rel="noopener noreferrer"
            className="text-ieee-blue hover:underline font-medium"
          >
            Learn more at ieee.org
          </a>
        </p>
      </div>
    </section>
  )
}
