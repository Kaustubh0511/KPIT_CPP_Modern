#include "computer.h"

std::ostream &operator<<(std::ostream &os, const computer &cmp)
{
     os << cmp.msp->m_make << '\t' <<
				cmp.msp->m_series << '\t' <<
				cmp.msp->m_processor << '\t' <<
				cmp.m_ram << '\t' <<
				cmp.m_hdd << '\t' <<
				cmp.m_mon << '\n';
    return os;
}
computer::computer( 
           string make,
			string series,
			string processor,
			string ram,
			string hd,
			string mon): 
          m_ram(ram),
			m_hdd(hd),
			m_mon(mon), msp(MSP::make_msp(make, series, processor)){ count++; }
