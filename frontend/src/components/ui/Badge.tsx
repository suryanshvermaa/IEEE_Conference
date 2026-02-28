interface BadgeProps {
  children: React.ReactNode
  variant?: 'gold' | 'blue' | 'green'
}

const variantClasses = {
  gold: 'bg-blue-100 text-ieee-blue border-blue-200',
  blue: 'bg-indigo-100 text-indigo-700 border-indigo-200',
  green: 'bg-slate-100 text-slate-600 border-slate-200',
}

export default function Badge({ children, variant = 'gold' }: BadgeProps) {
  return (
    <span
      className={`inline-flex items-center px-3 py-1 rounded-full text-xs font-semibold border tracking-wide uppercase ${variantClasses[variant]}`}
    >
      {children}
    </span>
  )
}
