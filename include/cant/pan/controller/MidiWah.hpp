//
// wah by wah on wah/wahh/waaaahhh
//

#ifndef CANTINA_PAN_WAH_HPP
#define CANTINA_PAN_WAH_HPP

#pragma once

#include <cant/pan/common/types.hpp>

#include <cant/pan/controller/MultiMidiController.hpp>

#include <cant/pan/timer/TimeUpdatable.hpp>

#include <cant/common/macro.hpp>
CANTINA_PAN_NAMESPACE_BEGIN

    class MidiTimer;

    class MidiWah : MultiMidiController<2>, public DeltaTimeUpdatable
    {
    public:
        /** -- methods -- **/
        // factory method
        static UPtr<MidiController> wah
        (
                size_u numberVoices,
                id_u8 channel,
                Array<id_u8, 2> wahwah,
                const UPtr<MidiTimer>& timer
       );

        void updateDelta(time_d tDelta) override;

    private:
        /** -- methods -- **/
        MidiWah
        (
                size_u numberVoices,
                id_u8 channel,
                Array<id_u8, 2> wahwah,
                const UPtr<MidiTimer>& timer
        );

        // event functions
        void beforeControlProcess(const MidiControlInternal& incomingControl) override;
        void beforeNoteProcess(const MidiNoteInternal& incomingNote) override;
        // private inheritance
        void IMPL_process(MidiNoteInternal& note) const override;
    };

CANTINA_PAN_NAMESPACE_END
#include <cant/common/undef_macro.hpp>

#endif //wah!
