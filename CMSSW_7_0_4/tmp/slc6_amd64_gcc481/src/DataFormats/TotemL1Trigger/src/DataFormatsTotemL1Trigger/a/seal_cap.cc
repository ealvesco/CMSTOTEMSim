static  const char* clnames[] = {
  "LCGReflex/RPCCBits",
  "LCGReflex/T1TriggerBits",
  "LCGReflex/T2TriggerBits",
  "LCGReflex/std::vector<T2TriggerBits>",
  "LCGReflex/std::vector<T1TriggerBits>",
  "LCGReflex/std::vector<RPCCBits>",
  "LCGReflex/edm::Wrapper<std::vector<T2TriggerBits> >",
  "LCGReflex/edm::Wrapper<T2TriggerBits>",
  "LCGReflex/edm::Wrapper<std::vector<T1TriggerBits> >",
  "LCGReflex/edm::Wrapper<T1TriggerBits>",
  "LCGReflex/edm::Wrapper<std::vector<RPCCBits> >",
  "LCGReflex/edm::Wrapper<RPCCBits>",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
