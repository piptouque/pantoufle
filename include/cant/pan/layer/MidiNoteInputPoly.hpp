//
// Created by binabik on 09/08/2020.
//

#ifndef CANTINA_TILDE_MIDINOTEINPUTPOLY_HPP
#define CANTINA_TILDE_MIDINOTEINPUTPOLY_HPP

#pragma once

#include <cant/pan/note/MidiNote.hpp>

#include <cant/pan/layer/MidiNoteLayer.hpp>

namespace cant::pan
{
    class MidiNoteInputPoly : public MidiNoteInputLayer
    {
    private:
        byte_m _channel;
        size_m _lastStolenVoice;
    private:
        CANT_NODISCARD virtual bool chooseVoice(size_m &voice, const MidiNoteInputData &data);
    public:
        CANT_EXPLICIT MidiNoteInputPoly(size_m numberVoices, byte_m channel);

        void flushChange();

        void receive(time_m tCurrent, const MidiNoteInputData& data) override;
    };
}

#endif //CANTINA_TILDE_MIDINOTEINPUTPOLY_HPP
