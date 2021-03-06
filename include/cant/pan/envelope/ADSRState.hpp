
#ifndef CANTINA_PAN_ADSRSTATE_HPP
#define CANTINA_PAN_ADSRSTATE_HPP

#pragma once

#include <cant/pan/common/types.hpp>

#include <cant/patterns/Slider.hpp>

#include <cant/pan/envelope/adsr_forward.hpp>

#include <cant/common/macro.hpp>
CANTINA_PAN_NAMESPACE_BEGIN

class ADSRState {
public:
  /** -- typedefs -- **/

  /** -- internal structures -- **/
  enum ADSRStateType {
    eAttack = 0, // he attac
    eDecay = 2,  // he decay
    // but most importantly
    eSustain = 1, // he won't throw sustain away
    eRelease = 3,
    eNotPlaying = 4
  };

  /** -- methods -- **/
  // should obviously only constructed by the envelope it is owned by.
  ADSRState();

  void updateTypeLength(const ADSREnvelope *env, time_d tDelta);
  void updateTypeLengthManual(const ADSREnvelope *env,
                              const MidiNoteInternal &note);

  void apply(MidiNoteInternal &note) const;

  CANT_NODISCARD ADSRStateType getType() const;
  CANT_NODISCARD time_d getLength() const;

private:
  /** -- methods -- **/

  CANT_NODISCARD type_d getVelocityRatio() const;

  void setType(const ADSREnvelope *env, ADSRStateType type, time_d length);
  void setTypeLengthManual(ADSREnvelope const * env, ADSRStateType type);

  CANT_NODISCARD bool justChangedPlaying() const;
  void raiseFlagChangedPlaying();
  void discardFlagChangedPlaying();

  CANT_NODISCARD bool isPlaying() const;
  CANT_NODISCARD bool isVarying() const;

  // static methods
  static void computeTypeLengthRecursive(ADSRStateType &type, time_d &length,
                                         adsr::ArrayLengths const & lengths);

  /**
   * @param ratios
   * @return actual velocity ratio for current type (will be null if not playing)
   */
  CANT_NODISCARD type_d
  getTypeTargetVelocityRatio(adsr::ArrayVelocityRatios const & ratios) const;

  /**
   * @param lengths
   * @return actual length for current type (will be null if not playing)
   */
  CANT_NODISCARD type_d
  getTypeTargetSlidingTime(adsr::ArrayLengths const & lengths) const;

  /** -- fields -- **/
  ADSRStateType m_type;
  time_d m_length;

  patterns::Slider<vel_d, time_d> m_velocitySlider;


  bool m_flagJustChangedPlaying;


  /** -- constants -- **/
  static CANT_CONSTEXPR time_d c_slidingTime = 100; // in milliseconds.

  /** -- friends -- **/
  friend class ADSREnvelope;
};

CANTINA_PAN_NAMESPACE_END
#include <cant/common/undef_macro.hpp>

#include <cant/pan/envelope/ADSRState.inl>

#endif // CANTINA_PAN_ADSRSTATE_HPP