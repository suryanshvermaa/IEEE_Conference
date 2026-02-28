import { Users, Globe, BookOpen, Cpu } from 'lucide-react'
import SectionHeader from '@/components/ui/SectionHeader'
import Card from '@/components/ui/Card'

const highlights = [
  {
    icon: Users,
    title: 'Nearly 10,000 Members',
    description: 'A global network of engineers and researchers across industry and academia.',
  },
  {
    icon: Globe,
    title: '100+ Global Chapters',
    description: 'Chapters spanning every region, connecting professionals worldwide.',
  },
  {
    icon: BookOpen,
    title: 'High-Impact Publications',
    description: 'Leading IEEE journals, conference proceedings, and standards development.',
  },
  {
    icon: Cpu,
    title: 'Industry-Focused Research',
    description: 'Practical solutions to real-world industrial challenges and innovation.',
  },
]

const focusAreas = [
  'Industrial Power Systems',
  'Energy Conversion',
  'Electric Drives',
  'Renewable Integration',
  'Automation',
  'Smart Technologies',
]

export default function About() {
  return (
    <section id="about" className="py-28 bg-white">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <SectionHeader
          badge="About IEEE IAS"
          title="Industry Applications"
          highlight="Society"
          subtitle="One of the largest and most dynamic technical societies within IEEE, advancing electrical and electronic engineering for industrial and commercial applications."
        />

        {/* Cards grid */}
        <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-4 gap-6 mb-16">
          {highlights.map(({ icon: Icon, title, description }) => (
            <Card key={title} hover glow>
              <div className="w-12 h-12 rounded-xl bg-blue-100 flex items-center justify-center mb-4 border border-blue-200">
                <Icon className="text-ieee-blue" size={22} />
              </div>
              <h3 className="text-slate-800 font-bold text-base mb-2">{title}</h3>
              <p className="text-slate-500 text-sm leading-relaxed">{description}</p>
            </Card>
          ))}
        </div>

        {/* Focus areas */}
        <div className="bg-blue-50 border border-blue-100 rounded-2xl p-8">
          <p className="text-ieee-blue font-semibold text-sm uppercase tracking-widest mb-5">
            IAS Knowledge Domains
          </p>
          <div className="flex flex-wrap gap-3">
            {focusAreas.map((area) => (
              <span
                key={area}
                className="px-4 py-2 rounded-full bg-white text-ieee-blue border border-blue-200 text-sm font-medium shadow-sm"
              >
                {area}
              </span>
            ))}
          </div>
        </div>
      </div>
    </section>
  )
}
