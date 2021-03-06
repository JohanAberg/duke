#pragma once

#include <duke/base/NonCopyable.hpp>
#include <duke/imageio/FrameData.hpp>

namespace duke {

/**
 * The result of an IO operation
 * - 'status' is one of SUCCESS, FAILURE.
 *   We could use other status for continuation if the process is segmented
 * - 'error' gives a message in case of failure.
 * - 'warning' gives a message if needed.
 */
struct IOResult : public noncopyable {
  enum Status {
    SUCCESS,
    FAILURE
  };

  Status status = FAILURE;
  std::string error;

  operator bool() const { return status == SUCCESS; }
};

/**
 * The result of an operation fetching an image
 */
struct ReadFrameResult : public IOResult {
  FrameData frame;
  attribute::Attributes readerAttributes;

  inline attribute::Attributes& attributes() { return frame.attributes; }
  inline const attribute::Attributes& attributes() const { return frame.attributes; }
};

}  // namespace duke
