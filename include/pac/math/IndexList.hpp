// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/parabolic-antenna-calculator
// ==============================================================
// Path /include/pac/math/IndexList.hpp
// Create the index list

#pragma once

#include <tuple>

using namespace std;

template <size_t NItem, size_t NLink>
struct IndexList
{
    array<size_t, NItem> count_;
    array<size_t, NItem + 1> offset_;
    array<size_t, NLink> linker_;

    template <typename Tuple>
    explicit consteval IndexList(const Tuple& lists)
    {
        [this]<size_t... Is>(const Tuple& tuple, index_sequence<Is...>) {
            count_ = array<size_t, sizeof...(Is)>{get<Is>(tuple).size()...};
            size_t index = 0;
            ([this, &index](size_t is, auto const& array)
            {
                offset_[is] = index;
                for (size_t i : array)
                    linker_[index++] = i;
            } (Is, get<Is>(tuple)), ...);
            offset_[NItem] = index;
        }(lists, make_index_sequence<tuple_size_v<Tuple>>{});
    }
};
