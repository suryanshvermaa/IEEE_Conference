export const NAV_LINKS = [
  { label: 'Home', href: '#home' },
  { label: 'About', href: '#about' },
  { label: 'Why Join', href: '#why-join' },
  { label: 'Chapter', href: '#chapter' },
  { label: 'Membership', href: '#membership' },
  { label: 'Vision', href: '#vision' },
] as const

export const WHY_JOIN_ITEMS = [
  {
    title: 'Seminars & Conferences',
    description:
      'Access to premier global IEEE events such as IEEE ECCE, IEEE APEC, and IAS Annual Meetings.',
    icon: 'calendar',
  },
  {
    title: 'Professional Publications',
    description:
      'Exposure to high-impact IEEE journals, conference proceedings, and technical standards.',
    icon: 'book-open',
  },
  {
    title: 'Advance Industry',
    description:
      'Contribute to real-world industrial solutions, standards development, and cutting-edge research.',
    icon: 'trending-up',
  },
] as const

export const CHAPTER_AIMS = [
  'Promote industry-relevant research and innovation',
  'Encourage student participation in global IAS conferences',
  'Facilitate technical talks by industry experts',
  'Support collaborative projects aligned with industrial needs',
  'Provide leadership and networking opportunities to students',
] as const

export const MEMBERSHIP_OPTIONS = [
  {
    title: 'IEEE Members',
    description:
      'Join IAS by paying a nominal additional society membership fee on top of your existing IEEE membership.',
    highlight: false,
  },
  {
    title: 'Students',
    description:
      'Join IAS at significantly reduced membership dues, enabling early professional exposure and global networking opportunities.',
    highlight: true,
  },
  {
    title: 'Organization Affiliates',
    description:
      'Join IAS at a reduced rate without full IEEE membership, subject to eligibility through approved professional bodies (EPE, IEE, VDE, IEEJ, ASME, ISA, etc.).',
    highlight: false,
  },
] as const

export const IAS_FOCUS_AREAS = [
  'Electric Drives',
  'Renewable Energy Integration',
  'Power Electronics',
  'Smart Grids',
  'Industrial Automation',
  'Energy Conversion',
] as const
