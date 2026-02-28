import { ArrowRight, ChevronDown } from 'lucide-react'
import Button from '@/components/ui/Button'
import Badge from '@/components/ui/Badge'

export default function Hero() {
  return (
    <section
      id="home"
      className="relative min-h-screen flex items-center justify-center overflow-hidden bg-gradient-to-br from-slate-50 via-blue-50 to-indigo-100"
    >
      {/* Subtle dot grid */}
      <div
        className="absolute inset-0 opacity-40"
        style={{
          backgroundImage: `radial-gradient(circle, #CBD5E1 1px, transparent 1px)`,
          backgroundSize: '32px 32px',
        }}
      />

      {/* Soft light blobs */}
      <div className="absolute top-1/4 left-1/4 w-[600px] h-[600px] bg-blue-200/50 rounded-full blur-[120px] pointer-events-none" />
      <div className="absolute bottom-1/4 right-1/4 w-[450px] h-[450px] bg-indigo-200/40 rounded-full blur-[100px] pointer-events-none" />
      <div className="absolute top-0 right-0 w-[350px] h-[350px] bg-sky-200/30 rounded-full blur-[90px] pointer-events-none" />

      <div className="relative z-10 max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 text-center py-32">
        {/* Badges row */}
        <div className="flex flex-wrap items-center justify-center gap-3 mb-8 animate-fade-in">
          <Badge variant="blue">IEEE Region 10</Badge>
          <Badge variant="gold">Kolkata Section</Badge>
          <Badge variant="green">Est. 2025</Badge>
        </div>

        {/* Heading */}
        <h1 className="text-5xl sm:text-6xl md:text-7xl lg:text-8xl font-extrabold tracking-tight text-slate-900 leading-none mb-6 animate-slide-up">
          IEEE{' '}
          <span className="bg-gradient-to-r from-ieee-blue via-blue-600 to-indigo-600 bg-clip-text text-transparent animate-[gradient_4s_ease_infinite] bg-[length:200%_200%]">
            IAS
          </span>
          <br />
          <span className="text-4xl sm:text-5xl md:text-6xl lg:text-7xl font-bold text-slate-700">
            Student Branch Chapter
          </span>
        </h1>

        <p className="text-xl sm:text-2xl font-semibold text-ieee-blue mb-4 animate-slide-up">
          National Institute of Technology Patna
        </p>

        <p className="text-base sm:text-lg text-slate-500 max-w-2xl mx-auto mb-12 leading-relaxed animate-fade-in">
          Bridging academia and industry through innovation, research, and global professional
          engagement in electrical and electronic engineering.
        </p>

        {/* CTA Buttons */}
        <div className="flex flex-col sm:flex-row gap-4 justify-center animate-fade-in">
          <Button as="a" href="#membership" variant="primary" size="lg">
            Join IEEE IAS
            <ArrowRight size={20} />
          </Button>
          <Button as="a" href="#about" variant="outline" size="lg">
            Learn More
          </Button>
        </div>

        {/* Stats row */}
        <div className="mt-20 grid grid-cols-2 md:grid-cols-4 gap-6 max-w-3xl mx-auto">
          {[
            { value: '10,000+', label: 'Global Members' },
            { value: '100+', label: 'Chapters Worldwide' },
            { value: '2025', label: 'Chapter Founded' },
            { value: 'Region 10', label: 'Asia-Pacific' },
          ].map((stat) => (
            <div key={stat.label} className="text-center">
              <p className="text-2xl md:text-3xl font-extrabold text-ieee-blue">{stat.value}</p>
              <p className="text-sm text-slate-500 mt-1">{stat.label}</p>
            </div>
          ))}
        </div>
      </div>

      {/* Scroll indicator */}
      <a
        href="#about"
        className="absolute bottom-8 left-1/2 -translate-x-1/2 text-slate-400 hover:text-ieee-blue transition-colors animate-bounce"
        aria-label="Scroll down"
      >
        <ChevronDown size={28} />
      </a>
    </section>
  )
}
