//
// Created by binabik on 22/07/2020.
//

#ifndef CANTINA_MIDICONTROLCOMPATIBLE_HPP
#define CANTINA_MIDICONTROLCOMPATIBLE_HPP

#pragma once

#include <cant/pan/control/MidiControlCompatible.hpp>

namespace cant::midi
{
    class MidiControlCompatible
    {
        CANT_NODISCARD virtual byte_m getControllerId() const = 0;
        CANT_NODISCARD virtual byte_m getValue() const = 0;
    };
}

#endif //CANTINA_MIDICONTROLCOMPATIBLE_HPP