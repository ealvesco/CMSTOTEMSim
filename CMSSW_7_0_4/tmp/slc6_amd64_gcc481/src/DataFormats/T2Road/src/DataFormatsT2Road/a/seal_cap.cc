static  const char* clnames[] = {
  "LCGReflex/T2Road",
  "LCGReflex/std::vector<T2Road>",
  "LCGReflex/edm::Wrapper<std::vector<T2Road> >",
  "LCGReflex/edm::Wrapper<std::vector<std::vector<T2Road> > >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
