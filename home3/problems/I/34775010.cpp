template <typename It, typename OutputIt>
OutputIt sideways_merge(It first1, It last1, It first2, It last2, OutputIt out) {
    auto out_it = out;
    if (first2 == last2) {
        for (auto it1 = first1; it1 != last1; ++it1) {
            *out_it = *it1;
            ++out_it;
        }
    } else {
        auto it2 = last2;
        --it2;
        bool is_emp = false;
        for (auto it1 = first1; ; ++it1) {
            while (!is_emp && (it1 == last1 || *it2 < *it1)) {
                *out_it = *it2;
                ++out_it;
                if (it2 == first2)
                    is_emp = true;
                else
                    --it2;
            }
            if (it1 == last1)
                break;
            *out_it = *it1;
            ++out_it;
        }
    }
    return out_it;
}