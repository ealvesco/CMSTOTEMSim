static  const char* clnames[] = {
  "LCGReflex/Totem::VFATFrame",
  "LCGReflex/std::vector<Totem::VFATFrame>",
  "LCGReflex/std::map<unsigned int,long>",
  "LCGReflex/std::map<unsigned int,Totem::OptoRxMetaData>",
  "LCGReflex/std::map<Totem::FramePosition,Totem::VFATFrame>",
  "LCGReflex/Totem::RawEvent",
  "LCGReflex/Totem::VFATFrameCollection",
  "LCGReflex/Totem::TriggerData",
  "LCGReflex/Totem::OptoRxMetaData",
  "LCGReflex/Totem::OptoRxVFATFrameCollection",
  "LCGReflex/Totem::FramePosition",
  "LCGReflex/Totem::SimpleVFATFrameCollection",
  "LCGReflex/edm::Wrapper<Totem::OptoRxVFATFrameCollection>",
  "LCGReflex/edm::Wrapper<Totem::SimpleVFATFrameCollection>",
  "LCGReflex/edm::Wrapper<Totem::RawEvent>",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
