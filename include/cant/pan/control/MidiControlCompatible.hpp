//
// Created by binabik on 22/07/2020.
//

#ifndef CANTINA_MIDICONTROLCOMPATIBLE_HPP
#define CANTINA_MIDICONTROLCOMPATIBLE_HPP

#pragma once

#include <cant/pan/common/types.hpp>

#include <cant/common/macro.hpp>
namespace cant::pan
{
    class MidiControlCompatible
    {
    public:
        /** -- methods -- **/
        // no virtual destructor for interfaces, prevents creating v-tables.
        CANT_NODISCARD virtual byte_m getChannel() const = 0;
        CANT_NODISCARD virtual byte_m getId() const = 0;
        CANT_NODISCARD virtual byte_m getValue() const = 0;
    };
}

#include <cant/common/undef_macro.hpp>
#endif //CANTINA_MIDICONTROLCOMPATIBLE_HPP
