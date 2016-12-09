static  const char* clnames[] = {
  "LCGReflex/TotemRawVFATFrame",
  "LCGReflex/TotemVFATFrameColl",
  "LCGReflex/std::vector<TotemRawVFATFrame>",
  "LCGReflex/std::vector<unsigned short*>",
  "LCGReflex/std::vector<__gnu_cxx::_Hashtable_node<std::pair<const int,int> >*>",
  "LCGReflex/std::equal_to<int>",
  "LCGReflex/std::_Select1st<std::pair<const int,int> >",
  "LCGReflex/std::allocator<__gnu_cxx::_Hashtable_node<std::pair<const int,int> > >",
  "LCGReflex/edm::Wrapper<TotemVFATFrameColl>",
  "LCGReflex/__gnu_cxx::hashtable<std::pair<const int,int>,int,__gnu_cxx::hash<int>,std::_Select1st<std::pair<const int,int> >,std::equal_to<int>,std::allocator<int> >",
  "LCGReflex/__gnu_cxx::hash<int>",
  "LCGReflex/__gnu_cxx::hash_map<int,int>",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
