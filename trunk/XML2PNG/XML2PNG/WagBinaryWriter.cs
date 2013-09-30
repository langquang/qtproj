namespace XML2PNG
{

    using System.IO;

    public class WagBinaryWriter : BinaryWriter
    {

        public WagBinaryWriter(Stream stream)  : base(stream) { }

        public WagBinaryWriter(Stream s, System.Text.Encoding e)  : base(s, e) { }

        public void ReadInt64BE(long l)
        {
            Write(Endian.IsBigEndian ? l : Endian.SwapInt64(l));

        }

        public void WriteInt16BE(short i)
        {
            Write(Endian.IsBigEndian ? i : Endian.SwapInt16(i));

        }

        public void WriteInt16LE(short i)
        {
            Write(Endian.IsLittleEndian ? i : Endian.SwapInt16(i));

        }

        public void WriteInt32BE(int i)
        {
            Write(Endian.IsBigEndian ? i : Endian.SwapInt32(i));

        }

        public void WriteInt32LE(int i)
        {
            Write(Endian.IsLittleEndian ? i : Endian.SwapInt32(i));

        }
        public void WriteInt64LE(long l)
        {
            Write(Endian.IsLittleEndian ? l : Endian.SwapInt64(l));

        }

        public void WriteUInt16BE(ushort l)
        {
            Write(Endian.IsBigEndian ? l : Endian.SwapUInt16(l));

        }

        public void WriteUInt16LE(ushort s)
        {
            Write(Endian.IsLittleEndian ? s : Endian.SwapUInt16(s));

        }

        public void WriteUInt32BE(uint i)
        {
            Write(Endian.IsBigEndian ? i : Endian.SwapUInt32(i));

        }

        public void WriteUInt32LE(uint i)
        {
            Write(Endian.IsLittleEndian ? i : Endian.SwapUInt32(i));

        }

        public void WriteUInt64BE(ulong l)
        {
            Write(Endian.IsBigEndian ? l : Endian.SwapUInt64(l));

        }

        public void WriteUInt64LE(ulong l)
        {
            Write(Endian.IsLittleEndian ? l : Endian.SwapUInt64(l));

        }

    }
}