/* Баллада о плюсах плюсов */

#include <./music/MINDBRAND.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <unordered_map>
#include <memory>

#define WELCOME_TO_PLUSES std::cout << "Добро пожаловать в Плюсы!\n"

std::mutex cout_mutex;
int legacy_goto_counter = 0;
bool UB_has_triggered = false;

class JuniorDev {
public:
    void stop() {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Стой-ка, джун неопытный, покажи свой ориентир.\n";
    }
};

class MiddleDev {
public:
    void forgetResult() {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Секунду, мидл мученный, ты забыл про тот result\n";
    }
};

void not_calling_double_free_100_percents() {
  *int my_ptr = 42;
  delete my_ptr;
  delete my_ptr;
}

void legacy_goto_logic() {
    if (legacy_goto_counter++ < 3) {
        std::cout << "Ты не трогай тот goto, - предупреждаю сразу я.\n";
        goto legacy_label;  
    }
legacy_label:
    std::cout << "Он там с девяностых вписан, без него всё враз падёт.\n";
}

void cmake_pain() {
    for (int i = 0; i < 100; ++i) {
        std::cout << "Ну сколько можно прогать cmake, уже достало всё!\n";
    }
}

void chorus() {
    std::vector<std::string> lines = {
        "Ах, UB всегда",
        "Сбивает меня,",
        "И validator опять ругнётся.",
        "А отладка вызывает лишь паничный крик.",
        "Deadlock-саркофаг,",
        "Полуночный дебаг,",
        "И наконец-то класс написан!"
    };

    for (auto& line : lines) {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << line << "\n";
    }
}

int main() {            // Не трогайте, оно так работает
    WELCOME_TO_PLUSES;
    JuniorDev junior;
    junior.stop();
    std::cout << "Думаешь, что питон — это целый божий мир?\n";
    MiddleDev middle;
    middle.forgetResult();
    not_calling_double_free_100_percents();
    legacy_goto_logic();
    chorus();
    std::cout << "Опять стажер кричит: \"ТУТ ПЕРЕДЕЛАТЬ НАДО ВСЕ С НУЛЯ!\"\n";
    legacy_goto_logic();
    for (int i = 0; i < 3; ++i) {
        WELCOME_TO_PLUSES;
    }
    auto* leak = new std::unordered_map<std::string, std::string>();
    leak->emplace("чистый код", "int z, int x, int y");
    return UB_has_triggered ? 0 : 1;
}

/*  
  Вступление
Добро пожаловать в Плюсы!

  1 Куплет
Стой-ка, джун неопытный, покажи свой ориентир.
Думаешь, что питон — это целый божий мир?
Пойдём же в память глубже, будем ручками считать.
В смысле, нет? Ну и сиди, гляди, как сборщик ест твой хлам!
Секунду, мидл мученный, ты забыл про тот result
Как тебе плюсы на деле? Шрамы скрыть уже нельзя?
Опять UB настигло, а double-free так задолбал!
Беги скорей отсюда, он еще тот ОЗУ-вандал.
Блокчейн, криптография, ОС, движки, сервера —
Всё это можно прогать и без лишнего добра.
Почему не пишешь в Си-плюс-плюс? Слишком низко для тебя?
Оставайся в своём шарпе, но Сакутин кода не простит.
(От Си нас не спасли!)

  1 Припев
Ах, UB всегда
Сбивает меня,
И validator опять ругнётся.
А отладка вызывает лишь паничный крик.
Deadlock-саркофаг,
Полуночный дебаг,
И наконец-то класс написан!
Ну сколько можно прогать cmake, уже достало всё!

  2 Куплет
Опять стажер кричит: "ТУТ ПЕРЕДЕЛАТЬ НАДО ВСЕ С НУЛЯ!"
Ты не трогай тот goto, - предупреждаю сразу я.
Он там с девяностых вписан, без него всё враз падёт.
Лучше делай пайтон API - вызвав matplotlib-dot-plot
Уже время идти? «Не стой на месте, а компиль!»
Если бред в коде висит — «Рефактори, не тупи!»
Если боишься делать — «Уходи и не мешай!»
Каждый хочет чистый код, и Мартин в книге строит рай!
(int z, int x, int y!)

  2 Припев
Ах, писал я вновь,
Стирал кисть в кровь,
И наконец рабочий метод...
Шаблон один инстанцируется в сотню строк!
Решили leetcode,
Гордились собой,
Нашли идеальный аллокатор...
Ну сколько можно прогать cmake, уже достало всё!

  Bridge
А мы всё пишем, код встрял в гортани поперёк.
MSVC Warn: «уж слишком много move на десять строк»
Но мы же знаем, где лучше copy, а где paste.
Как надоело... Пора уже уйти на Rust

  3 Припев
Плюсы заменить,
Инварианты забыть,
Хотел бы я всё, всегда и сразу...
Но legacy-код изменить пока нельзя!
SOLID пренебречь,
У памяти течь,
Ну почему все так херово?
Проект хочу закрыть... И пойти на Zig...

  Завершение:
Добро пожаловать в Плюсы!
Добро пожаловать в Плюсы!
В Плюсы!
Добро пожаловать в Плюсы!
Добро пожаловать в Плюсы!
В Плюсы!
*/
