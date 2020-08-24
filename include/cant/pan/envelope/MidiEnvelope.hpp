//
// Created by piptouque on 28/04/2020.
//

#ifndef PANTOUFLEENVELOPE_HPP
#define PANTOUFLEENVELOPE_HPP

#pragma once


#include <cant/common/formatting.hpp>
#include <cant/pan/common/types.hpp>

#include <cant/pan/processor/MidiProcessor.hpp>

#include <cant/common/macro.hpp>
namespace cant::pan
{

    /**
     * Envelopes should not have internal states
     * but compute everything from input note (contains starting time)
     * and current time.
     **/
    template <typename T>
    class MidiEnvelope : public MidiProcessorMemory
    {
    private:
        time_m _tCurrent;
    protected:
        CANT_NODISCARD time_m getCurrentTime() const;
    public:
        CANT_EXPLICIT MidiEnvelope(size_m numberVoices);

        void update(time_m tCurrent) override;
        void process(MidiNoteInternal& note) override = 0;

        virtual void flushChange() = 0;
    };


    class ToneEnvelope : public MidiEnvelope<tone_m>
    {
    public:
        CANT_EXPLICIT ToneEnvelope(size_m numberVoices);
        void process(MidiNoteInternal& note) override = 0;

        void flushChange() override = 0;
    };


    class VelocityEnvelope : public MidiEnvelope<vel_m>
    {
    public:
        CANT_EXPLICIT VelocityEnvelope(size_m numberVoices);
        void process(MidiNoteInternal& note) override = 0;

        void flushChange() override = 0;
    };
}
#include <cant/common/undef_macro.hpp>

#include "MidiEnvelope.inl"

#endif //PANTOUFLEENVELOPE_HPP
