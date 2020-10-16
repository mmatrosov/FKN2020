#include <algorithm>
#include <set>
#include <tuple>

struct StockItem {
    int weight;
    int volume;
    int pos;

    struct CmpByVolume {
        bool operator()(StockItem const& lhs, StockItem const& rhs) const {
            return std::make_tuple(lhs.volume, -lhs.pos) < std::make_tuple(rhs.volume, -rhs.pos);
        }
    };
    struct CmpByWeight {
        bool operator()(StockItem const& lhs, StockItem const& rhs) const {
            return std::make_tuple(lhs.weight, -lhs.pos) < std::make_tuple(rhs.weight, -rhs.pos);
        }
    };
};

class Stock {
    std::set<StockItem, StockItem::CmpByWeight> mItemsByWeight;
    std::set<StockItem, StockItem::CmpByVolume> mItemsByVolume;
    int mCounter = 0;

    void del(StockItem it) {
        mItemsByVolume.erase(it);
        mItemsByWeight.erase(it);
    }

public:
    void add(int w, int v) {
        StockItem it{w, v, mCounter++};
        mItemsByVolume.insert(it);
        mItemsByWeight.insert(it);
    }

    int get_by_w(int w) {
        auto it = mItemsByWeight.lower_bound({w, w, mCounter});
        if (it == mItemsByWeight.end()) {
            return -1;
        }
        int pos = it->pos;
        del(*it);
        return pos;
    }
    int get_by_v(int v) {
        auto it = mItemsByVolume.lower_bound({v, v, mCounter});
        if (it == mItemsByVolume.end()) {
            return -1;
        }
        int pos = it->pos;
        del(*it);
        return pos;
    }
};