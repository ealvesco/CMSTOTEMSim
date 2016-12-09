static  const char* clnames[] = {
  "LCGReflex/VFATStatus",
  "LCGReflex/std::bitset<8>",
  "LCGReflex/edm::Wrapper<std::bitset<8> >",
  "LCGReflex/edm::Wrapper<VFATStatus>",
  "LCGReflex/std::map<Totem::FramePosition,VFATStatus>",
  "LCGReflex/edm::Wrapper<std::map<Totem::FramePosition,VFATStatus> >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
