static  const char* clnames[] = {
  "LCGReflex/T2StripDigi",
  "LCGReflex/TotemDigiCollection<T2DetId,T2PadDigi>",
  "LCGReflex/TotemDigiCollection<T2DetId,T2StripDigi>",
  "LCGReflex/T2PadDigi",
  "LCGReflex/std::pair<T2DetId,std::vector<T2PadDigi> >",
  "LCGReflex/std::pair<T2DetId,std::vector<T2StripDigi> >",
  "LCGReflex/std::vector<T2PadDigi>",
  "LCGReflex/std::vector<T2StripDigi>",
  "LCGReflex/std::map<T2DetId,std::vector<T2PadDigi> >",
  "LCGReflex/std::map<T2DetId,std::vector<T2StripDigi> >",
  "LCGReflex/edm::Wrapper<std::pair<T2DetId,std::vector<T2PadDigi> > >",
  "LCGReflex/edm::Wrapper<TotemDigiCollection<T2DetId,T2PadDigi> >",
  "LCGReflex/edm::Wrapper<std::pair<T2DetId,std::vector<T2StripDigi> > >",
  "LCGReflex/edm::Wrapper<TotemDigiCollection<T2DetId,T2StripDigi> >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
