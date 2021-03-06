#pragma once

#include "IMediaStream.hpp"

namespace sequence {
struct Item;
}

namespace duke {

class DiskMediaStream final : public duke::IMediaStream {
 public:
  DiskMediaStream(const attribute::Attributes& readerOptions, const sequence::Item& item);

  ReadFrameResult process(const size_t frame) const override;

  bool isForwardOnly() const override;

  const attribute::Attributes& getState() const override;

 private:
  std::unique_ptr<IMediaStream> m_pDelegate;
};

} /* namespace duke */
