using System.IO;

namespace XML2PNG
{
    public class WagBinaryReader : BinaryReader
    {
        public WagBinaryReader(Stream stream)
            : base(stream) { }

        public WagBinaryReader(Stream s, System.Text.Encoding e)
            : base(s, e) { }

        public short ReadInt16BE()
        {
            return Endian.IsBigEndian ? ReadInt16() : Endian.SwapInt16(ReadInt16());
        }

        public short ReadInt16LE()
        {
            return Endian.IsLittleEndian ? ReadInt16() : Endian.SwapInt16(ReadInt16());
        }

        public int ReadInt32BE()
        {
            return Endian.IsBigEndian ? ReadInt32() : Endian.SwapInt32(ReadInt32());
        }

        public int ReadInt32LE()
        {
            return Endian.IsLittleEndian ? ReadInt32() : Endian.SwapInt32(ReadInt32());
        }

        public long ReadInt64BE()
        {
            return Endian.IsBigEndian ? ReadInt64() : Endian.SwapInt64(ReadInt64());
        }

        public long ReadInt64LE()
        {
            return Endian.IsLittleEndian ? ReadInt64() : Endian.SwapInt64(ReadInt64());
        }

        public ushort ReadUInt16BE()
        {
            return Endian.IsBigEndian ? ReadUInt16() : Endian.SwapUInt16(ReadUInt16());
        }

        public ushort ReadUInt16LE()
        {
            return Endian.IsLittleEndian ? ReadUInt16() : Endian.SwapUInt16(ReadUInt16());
        }

        public uint ReadUInt32BE()
        {
            return Endian.IsBigEndian ? ReadUInt32() : Endian.SwapUInt32(ReadUInt32());
        }

        public uint ReadUInt32LE()
        {
            return Endian.IsLittleEndian ? ReadUInt32() : Endian.SwapUInt32(ReadUInt32());
        }

        public ulong ReadUInt64BE()
        {
            return Endian.IsBigEndian ? ReadUInt64() : Endian.SwapUInt64(ReadUInt64());
        }

        public ulong ReadUInt64LE()
        {
            return Endian.IsLittleEndian ? ReadUInt64() : Endian.SwapUInt64(ReadUInt64());
        }
    }
}