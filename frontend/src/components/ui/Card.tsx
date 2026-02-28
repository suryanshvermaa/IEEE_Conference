import React from 'react'

interface CardProps {
  children: React.ReactNode
  className?: string
  hover?: boolean
  glow?: boolean
}

export default function Card({ children, className = '', hover = false, glow = false }: CardProps) {
  return (
    <div
      className={`
        relative rounded-2xl bg-white border border-slate-200 shadow-sm p-6
        ${hover ? 'transition-all duration-300 hover:-translate-y-1 hover:shadow-lg hover:border-blue-200 cursor-pointer' : ''}
        ${glow ? 'hover:shadow-blue-100' : ''}
        ${className}
      `}
    >
      {children}
    </div>
  )
}
