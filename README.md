http://wiki.cs.hse.ru/Основы_и_методология_программирования_на_ПМИ_2020/2021_(пилотный_поток)

## Требования

- isupper(), islower() etc.
- макросы
- using namespace
- range-based for obligatory!
- copy-paste
- clang-format
- без транслита

## Темы на разобрать

- mixing of static and dynamic polymorphism (ex. E. Интеграл)
- Задача ["Дерево выражений"](https://www.coursera.org/learn/c-plus-plus-brown/programming/J9df7/dierievo-vyrazhienii) из поясов ([решение](https://github.com/yandexdataschool/onlinecpp/blob/master/grader/grading-files/smart_pointers/expression/solutions/correct.cpp)). Она же задача [J. Выражение](https://contest.yandex.ru/contest/19576/problems/J/).
  - Иерархия классов
  - Не следует пользоваться `dynamic_cast`. А если пользоваться - то только к интерфейсам.
- range-based for - разные типы для начала и конца, по задаче [K. Итератор по контейнеру контейнеров](https://contest.yandex.ru/contest/19576/problems/K/)
- полезные онлайн ресурсы
  - https://gcc.godbolt.org/
  - https://wandbox.org/
  - https://quick-bench.com/
- copy+move parameters in constructors
- r-value refs

## Разобрали

- `const_cast` для устранения дублирования кода в const/non-const перегрузках (см. задачу [Deque](https://contest.yandex.ru/contest/19568/problems/C/))
- const pointers vs. pointers to const, const references vs. references to const
- `count()` vs. `operator[]` vs. `find()` for containers
- `std::search()` for [G. Count subsegments](https://contest.yandex.ru/contest/19568/problems/G/)
- "выделить в хипе и на стеке" против "динамически и автоматически"
- разные способы представления матрицы: динамический массив динамических массивов, один динамический массив, один автоматический массив
- explicit constructors
- list of initialization
- default member initialization
- std::make_reverse_iterator + std::merge для I3
- template code deduplication: explicit function/variable template specialization, constexpr if, function overloading, tag dispatching, typeid comparison (bad)
- managed vs unmanaged vs interpreted
- задача [О1](https://contest.yandex.ru/contest/19571/problems/O/): find_if, not_fn
- std::hypot
- signed vs. unsigned, ssize()
- string = string + char, string = move(string) + char, 
- в каком случае сравнение на == строк представленных как char* будет работать (пример из жизни)
- pure function это лучше чем функция в выходными параметрами, которая лучше чем функция со скрытым состоянием
- вариации лексикографического сравнения: pair, tuple, tie, make_pair(), перестановка аргументов, cref()
- кэши и локальность
- bool - это не 0/1
- static_cast для расширения типа
- const auto& + char
- continue вместо else
- глобальные переменные - только const
- один проход вместо нескольких
- static локальные переменные
- std::size()
- массив из флагов
- ранний выход
- binary literals 0b0011'1111;
- std::countl_one()
- switch для задачи B1
- 'a', 'z' - коды, а не числа. пример с сортировкой 'a', 'b', 'A'. индексы и итерирование
- std::vector<bool>, iteration example
