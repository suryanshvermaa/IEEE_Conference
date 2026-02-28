import { CalendarDays, BookOpenText, TrendingUp } from 'lucide-react'
import SectionHeader from '@/components/ui/SectionHeader'

const reasons = [
  {
    icon: CalendarDays,
    number: '01',
    title: 'Seminars & Conferences',
    description:
      'Access to premier global events such as IEEE ECCE, IEEE APEC, and IAS Annual Meetings that bring together industry leaders and researchers.',
    color: 'from-ieee-blue to-blue-500',
  },
  {
    icon: BookOpenText,
    number: '02',
    title: 'Professional Publications',
    description:
      'Exposure to high-impact IEEE journals, conference proceedings, and cutting-edge technical standards that keep you ahead in your field.',
    color: 'from-indigo-600 to-indigo-400',
  },
  {
    icon: TrendingUp,
    number: '03',
    title: 'Advance Industry',
    description:
      'Contribute to real-world industrial solutions and standards development, making a tangible impact on how electrical systems are built and operated.',
    color: 'from-blue-400 to-sky-400',
  },
]

export default function WhyJoin() {
  return (
    <section id="why-join" className="py-28 bg-ieee-subtle section-muted">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <SectionHeader
          badge="Why Join"
          title="Three Reasons to Join"
          highlight="IEEE IAS"
          subtitle="Unlock a world of professional opportunities, knowledge, and global connections."
        />

        <div className="grid grid-cols-1 md:grid-cols-3 gap-8">
          {reasons.map(({ icon: Icon, number, title, description, color }) => (
            <div
              key={number}
              className="group relative rounded-2xl overflow-hidden border border-slate-200 hover:border-blue-300 transition-all duration-300 hover:-translate-y-1 hover:shadow-xl bg-white shadow-sm"
            >
              {/* Top gradient accent */}
              <div className={`h-1 w-full bg-gradient-to-r ${color}`} />

              <div className="p-8">
                <div className="flex items-start justify-between mb-6">
                  <div className="w-14 h-14 rounded-xl bg-blue-50 border border-blue-200 flex items-center justify-center group-hover:bg-blue-100 transition-colors">
                    <Icon className="text-ieee-blue" size={26} />
                  </div>
                  <span className="text-6xl font-black text-slate-100 leading-none select-none">
                    {number}
                  </span>
                </div>

                <h3 className="text-slate-800 font-bold text-xl mb-3">{title}</h3>
                <p className="text-slate-500 text-sm leading-relaxed">{description}</p>
              </div>
            </div>
          ))}
        </div>
      </div>
    </section>
  )
}
