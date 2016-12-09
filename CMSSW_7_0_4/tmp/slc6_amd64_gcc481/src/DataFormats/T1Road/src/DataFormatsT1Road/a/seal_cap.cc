static  const char* clnames[] = {
  "LCGReflex/T1RecHitGlobal",
  "LCGReflex/std::vector<T1RecHitGlobal>",
  "LCGReflex/edm::Wrapper<T1RecHitGlobal>",
  "LCGReflex/GlobalErrorBase<double,ErrorMatrixTag>",
  "LCGReflex/std::vector<std::vector<T1RecHitGlobal> >",
  "LCGReflex/DeepCopyPointer<CLHEP::HepSymMatrix>",
  "LCGReflex/edm::Wrapper<std::vector<std::vector<T1RecHitGlobal> > >",
  "LCGReflex/edm::Wrapper<std::vector<T1RecHitGlobal> >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
