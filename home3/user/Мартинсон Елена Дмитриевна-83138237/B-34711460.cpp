template <typename InIter, typename OutIter, typename Predicate>
OutIter remove_copy_if(InIter first, InIter last, OutIter out, Predicate f) {
  for (auto it = first; it != last; ++it) {
    if (!f(*it)) {
      *out++ = *it;
    }
  }
  return out;
}
