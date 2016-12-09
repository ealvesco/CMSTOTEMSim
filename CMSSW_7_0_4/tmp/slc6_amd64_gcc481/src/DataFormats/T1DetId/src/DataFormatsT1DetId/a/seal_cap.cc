static  const char* clnames[] = {
  "LCGReflex/T1DetId",
  "LCGReflex/std::pair<T1DetId,std::pair<unsigned int,unsigned int> >",
  "LCGReflex/edm::Wrapper<std::pair<T1DetId,std::pair<unsigned int,unsigned int> > >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
