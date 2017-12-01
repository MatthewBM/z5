#pragma once

#include <vector>
#include "z5/types/types.hxx"

namespace z5 {
namespace compression {

    // abstract basis class for compression
    template<typename T>
    class CompressorBase {

    public:
        //
        // API -> must be implemented by child classes
        //

        virtual void compress(const T *, std::vector<T> &, size_t) const = 0;
        virtual void decompress(const std::vector<T> &, T *, size_t) const = 0;
        virtual types::Compressor type() const = 0;
        virtual void getCodec(std::string &) const = 0;
        // default implementation for level (nt needed for raw)
        virtual int getLevel() const {return 0;}
        // default implementations for shuffle (this parameter only applies to blosc)
        virtual int getShuffle() const {return 0;}

    };


}
} // namespace::z5
