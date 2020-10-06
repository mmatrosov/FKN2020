#include <algorithm>
#include <vector>

// Предполагается, что у сравниваемых объектов типа C нет явных операторов < и ==,
// но их можно сериализовать в строку (в набор байтов) с помощью функции Serialize.
// Поэтому эта функция сравнивает сериализованные представления объектов.
template <typename C>
bool Compare(const C& x, const C& y) {
    return x.Serialize() < y.Serialize();
}

// Функция должна вернуть false, если наборы a и b совпадают с точностью до перестановки,
// и true в противном случае
template <typename C>
bool HaveDifference(std::vector<C> a, std::vector<C> b) {
    if (a.size() != b.size()) {
        return true;
    }
    std::sort(a.begin(), a.end(), Compare<C>);
    std::sort(b.begin(), b.end(), Compare<C>);
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].Serialize() != b[i].Serialize())
            return true;
    }
    return false;
}
