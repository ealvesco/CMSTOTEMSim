static  const char* clnames[] = {
  "LCGReflex/T1RecHit2D",
  "LCGReflex/edm::RangeMap<T1DetId,edm::OwnVector<T1RecHit2D,edm::ClonePolicy<T1RecHit2D> >,edm::ClonePolicy<T1RecHit2D> >",
  "LCGReflex/std::vector<T1RecHit2D*>",
  "LCGReflex/std::map<T1DetId,std::pair<unsigned int,unsigned int> >",
  "LCGReflex/edm::Wrapper<edm::RangeMap<T1DetId,edm::OwnVector<T1RecHit2D,edm::ClonePolicy<T1RecHit2D> >,edm::ClonePolicy<T1RecHit2D> > >",
  "LCGReflex/edm::OwnVector<T1RecHit2D,edm::ClonePolicy<T1RecHit2D> >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
