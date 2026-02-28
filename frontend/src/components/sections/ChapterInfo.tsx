import { CheckCircle2, MapPin, Building2, Zap } from 'lucide-react'
import SectionHeader from '@/components/ui/SectionHeader'
import { CHAPTER_AIMS, IAS_FOCUS_AREAS } from '@/constants'

export default function ChapterInfo() {
  return (
    <section id="chapter" className="py-28 bg-white">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <SectionHeader
          badge="Our Chapter"
          title="IEEE IAS SBC –"
          highlight="NIT Patna"
          subtitle="Established in 2025 under the Department of Electrical Engineering, driving industry-oriented research and global engagement."
        />

        <div className="grid grid-cols-1 lg:grid-cols-2 gap-12 items-center">
          {/* Left — info cards */}
          <div className="flex flex-col gap-5">
            {[
              {
                icon: Building2,
                label: 'Institution',
                value: 'National Institute of Technology Patna',
              },
              {
                icon: MapPin,
                label: 'IEEE Region',
                value: 'Region 10 (Asia-Pacific)',
              },
              {
                icon: Zap,
                label: 'Section',
                value: 'IEEE Kolkata Section',
              },
            ].map(({ icon: Icon, label, value }) => (
              <div
                key={label}
                className="flex items-center gap-5 p-5 rounded-xl bg-slate-50 border border-slate-200"
              >
                <div className="w-12 h-12 rounded-lg bg-blue-100 flex items-center justify-center flex-shrink-0 border border-blue-200">
                  <Icon className="text-ieee-blue" size={20} />
                </div>
                <div>
                  <p className="text-slate-400 text-xs uppercase tracking-wide mb-0.5">{label}</p>
                  <p className="text-slate-900 font-semibold text-sm">{value}</p>
                </div>
              </div>
            ))}

            {/* Focus areas */}
            <div className="p-5 rounded-xl bg-slate-50 border border-slate-200">
              <p className="text-slate-400 text-xs uppercase tracking-wide mb-3">Research Focus Areas</p>
              <div className="flex flex-wrap gap-2">
                {IAS_FOCUS_AREAS.map((area) => (
                  <span
                    key={area}
                    className="px-3 py-1 rounded-full text-xs font-medium bg-blue-100 text-ieee-blue border border-blue-200"
                  >
                    {area}
                  </span>
                ))}
              </div>
            </div>
          </div>

          {/* Right — aims list */}
          <div className="flex flex-col gap-4">
            <p className="text-ieee-blue font-semibold text-sm uppercase tracking-widest mb-2">
              Chapter Aims & Objectives
            </p>
            {CHAPTER_AIMS.map((aim) => (
              <div key={aim} className="flex items-start gap-4 p-4 rounded-xl hover:bg-blue-50 transition-colors group">
                <CheckCircle2
                  className="text-ieee-blue flex-shrink-0 mt-0.5 group-hover:scale-110 transition-transform"
                  size={20}
                />
                <p className="text-slate-600 text-sm leading-relaxed">{aim}</p>
              </div>
            ))}
          </div>
        </div>
      </div>
    </section>
  )
}
