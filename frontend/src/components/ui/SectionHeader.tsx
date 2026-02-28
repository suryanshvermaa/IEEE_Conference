interface SectionHeaderProps {
  badge?: string
  title: string
  highlight?: string
  subtitle?: string
  centered?: boolean
}

export default function SectionHeader({
  badge,
  title,
  highlight,
  subtitle,
  centered = true,
}: SectionHeaderProps) {
  return (
    <div className={`mb-14 ${centered ? 'text-center' : 'text-left'}`}>
      {badge && (
        <span className="inline-block px-4 py-1.5 rounded-full text-xs font-bold tracking-widest uppercase bg-blue-100 text-ieee-blue border border-blue-200 mb-4">
          {badge}
        </span>
      )}
      <h2 className="text-4xl md:text-5xl font-extrabold text-slate-900 leading-tight">
        {title}{' '}
        {highlight && (
          <span className="bg-gradient-to-r from-ieee-blue to-indigo-600 bg-clip-text text-transparent">
            {highlight}
          </span>
        )}
      </h2>
      {subtitle && (
        <p className="mt-4 text-lg text-slate-500 max-w-2xl mx-auto leading-relaxed">
          {subtitle}
        </p>
      )}
    </div>
  )
}
