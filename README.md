http://wiki.cs.hse.ru/Основы_и_методология_программирования_на_ПМИ_2020/2021_(пилотный_поток)

## Требования

- isupper(), islower() etc.
- макросы
- using namespace
- range-based for obligatory!
- copy-paste
- clang-format
- без транслита

## По посылкам 

- лучше получать ответ в явном виде
- IIFE на примере B-34059851-gcc_docker2-OK+
- задача [О1](https://contest.yandex.ru/contest/19571/problems/O/): find_if, not_fn
- std::hypot
- long double

## Темы на разобрать

- std::make_reverse_iterator + std::merge для I3
- template code deduplication
- managed vs unmanaged vs interpreted
- двусвязный список
- r-value refs
- const-ness
- Задача n-граммы
 
## Разобрали

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
