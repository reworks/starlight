///
/// Source.hpp
/// frb
///
/// Refer to LICENSE.txt for more details.
///

#ifndef FRB_SOURCE_HPP_
#define FRB_SOURCE_HPP_

#include <vector>

#include "frb/buffer/Buffer.hpp"
#include "frb/buffer/BufferStream.hpp"

#include "protostar/system/Concepts.hpp"

///
/// Core namespace.
///
namespace frb
{
	///
	/// Origin of the audio sound.
	///
	class Source final
	{
	public:
		///
		/// \brief Default constructor.
		///
		/// Generates source buffer(s).
		///
		Source();

		///
		/// \brief Default destructor.
		///
		/// Destroys source buffer(s).
		///
		~Source() noexcept;

		///
		/// Queue a buffer for the source to play.
		///
		/// \param buffer Buffer to queue.
		///
		void queue(frb::Buffer* buffer) noexcept;

		///
		/// Queue a streamed buffer for the source to play through.
		///
		/// \param stream_buffer Buffer containing streamed from disk buffers to play.
		///
		void queue(BufferStream* stream_buffer);

		///
		/// Queue a set of buffers for the source to play through.
		///
		/// \param buffers Array of buffers you want to play in a queue.
		///
		void queue(const std::vector<frb::Buffer>& buffers);

		///
		/// Raw queue of buffer(s) to play.
		///
		/// \param buffer_array Array of buffers you want to play in a queue.
		/// \param size The size/length of buffer_array.
		///
		void queue(const ALuint* buffer_array, const size_t size) noexcept;

		///
		/// \brief Play source.
		///
		/// Plays source from beginning or pause point.
		///
		void play() noexcept;

		///
		/// Pause source.
		///
		void pause() noexcept;

		///
		/// \brief Stop source.
		///
		/// Starts again from beginning when play() or resume() are called.
		///
		void stop() noexcept;

		///
		/// Rewind source to beginning.
		///
		void rewind() noexcept;

		///
		/// \brief Audio pitch.
		///
		/// Negative values automatically converted to positive.
		///
		/// \param pitch Multiplier value. I.e. 0.5f is a *0.5 multiplier.
		///
		void set_pitch(pr::not_negative auto pitch) noexcept;

		///
		/// \brief Audio gain.
		///
		/// Negative values automatically converted to positive.
		///
		/// \param gain Multiplier value. I.e. 0.5f is a *0.5 multiplier.
		///
		void set_gain(pr::not_negative auto gain) noexcept;

		///
		/// \brief Set RollOff factor for source.
		///
		/// \param factor Floating point factor value.
		///
		void set_rolloff_factor(pr::not_negative auto factor) noexcept;

		///
		/// \brief Set maximum distance from which there is no attenuation afterwards.
		///
		/// \param distance Floating point distance value.
		///
		void set_max_distance(const float distance) noexcept;

		///
		/// \brief Configure audio cone.
		///
		/// \param outerGain The gain when outside the oriented cone.
		/// \param innerAngle The gain when inside the oriented cone.
		/// \param outerAngle Outer angle of the sound cone, in degrees. Default is 360.
		///
		void set_cone(const float outer_gain, const float inner_angle, const float outer_angle = 360.0f) noexcept;

		///
		/// \brief Specifies the current location of the object in the world coordinate system.
		///
		/// \param x position in world.
		/// \param y position in world.
		/// \param z position in world.
		///
		void set_position(const float x, const float y, const float z) noexcept;

		///
		/// \brief Specifies the current velocity (speed and direction) of the object, in theworld coordinate system
		///
		/// \param x X velocity.
		/// \param y Y velocity.
		/// \param z Z velocity.
		///
		void set_velocity(const float x, const float y, const float z) noexcept;

		///
		/// \brief Source is directional. The sound emission is presumed to be symmetric around the direction vector.
		///
		/// \param x position in world.
		/// \param y position in world.
		/// \param z position in world.
		///
		void set_direction(const float x, const float y, const float z) noexcept;

		///
		/// \brief Should the source repeat upon reaching the end.
		///
		/// \param True to repeat.
		///
		void set_looping(bool looping) noexcept;

		///
		/// \brief Get current state of the source.
		///
		/// \return Enum. AL_PLAYING, AL_STOPPED, etc...
		///
		ALint get_state() noexcept;

		///
		/// Get the OpenAL internal int id / handle.
		///
		/// \return Const ALuint handle integer.
		///
		const ALuint handle() const noexcept;

		///
		/// \brief Destroy all memory and OpenAL data.
		///
		/// Calls stop().
		///
		void destroy() noexcept;

	private:
		///
		/// Handle to source.
		///
		ALuint m_source;
	};
} // namespace frb

#endif