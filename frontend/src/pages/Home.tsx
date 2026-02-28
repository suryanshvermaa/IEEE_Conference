import Navbar from '@/components/layout/Navbar'
import Footer from '@/components/layout/Footer'
import Hero from '@/components/sections/Hero'
import About from '@/components/sections/About'
import WhyJoin from '@/components/sections/WhyJoin'
import ChapterInfo from '@/components/sections/ChapterInfo'
import Membership from '@/components/sections/Membership'
import Vision from '@/components/sections/Vision'

export default function Home() {
  return (
    <>
      <Navbar />
      <main>
        <Hero />
        <About />
        <WhyJoin />
        <ChapterInfo />
        <Membership />
      </main>
      <Footer />
    </>
  )
}
