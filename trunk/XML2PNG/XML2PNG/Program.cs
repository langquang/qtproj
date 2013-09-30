using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Drawing.Imaging;
using System.Drawing.Drawing2D;
using System.Xml.Linq;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace XML2PNG
{
    class Program
    {
	    public static string NAME_ATLAS_OUT_PUT = "atlas.bin";
	    public static string NAME_TEXT_OUT_PUT = "text.bin";
	    public static string NAME_FONT_OUT_PUT = "vn.bin";

	    public static string BUILD_ALL = "all";
	    public static string BUILD_TEXT = "text";
	    public static string BUILD_ATLAS = "atlas";
	    public static string BUILD_FONT = "font";
	static void Main(string[] args)
	{
		Console.WriteLine("Enter your action 'text' & 'atlas' & 'font'");
		string line = Console.ReadLine();
		line = line.ToLower();
		string[] actions = line.Split('&');
		foreach (string action in actions)
		{
			action.Trim();
			if (action == BUILD_ALL)
			{
				buildText();
				buildAtlas();
				buildFonts();
			} 
			else
			{
				if (action == BUILD_TEXT) buildText();
				if (action == BUILD_ATLAS) buildAtlas();
				if (action == BUILD_FONT) buildFonts();
			}

		}
		Console.Read();
	}

	static public void buildText()
	{
		Console.WriteLine("============= TEXT ==================");
		MemoryStream stream = new MemoryStream();
		WagBinaryWriter writer = new WagBinaryWriter(stream);
		DirectoryInfo d = new DirectoryInfo(Directory.GetCurrentDirectory());
		// remain num of Pack
		writer.WriteInt16BE(0);
		var npack = 0;
		foreach (var file in d.GetFiles("*.text"))
		{
			log(file.FullName);
			npack += writeText(writer, file.FullName);
			// write num of pack
			long realSeek = writer.BaseStream.Position;
			writer.BaseStream.Position = 0;
			writer.WriteInt16BE((short)npack);
			writer.BaseStream.Position = realSeek;
			write2Bin(stream, NAME_TEXT_OUT_PUT);
		}
	}

	static public int writeText(WagBinaryWriter writer, string filePath)
	{
		int num = 0;
		string[] filenames = filePath.Split('\\');
		string filename = filenames[filenames.Length - 1];
		// read every line
		StreamReader reader = new StreamReader(filePath);
		string line = "";
		while ((line = reader.ReadLine()) != null)
		{
			line.Trim();
			if (line.Length == 0)
			{
				throw new Exception("Error line: empty");
			}
			string[] data = line.Split('=');
			if (data.Length == 2)
			{
				writer.Write(data[0]);
				writer.Write(data[1]);
				num++;
			}
			else
			{
				throw new Exception("Error line: " + line);
			}
		}
		
		return num;
	} 

	static public void buildAtlas()
	{
		Console.WriteLine("============= ATLAS ==================");
		MemoryStream stream = new MemoryStream();
		WagBinaryWriter writer = new WagBinaryWriter(stream);
		DirectoryInfo d = new DirectoryInfo(Directory.GetCurrentDirectory());
		// remain num of Pack
		writer.WriteInt16BE(0);
		var npack = 0;
		foreach (var file in d.GetFiles("*.xml"))
		{
			log(file.FullName);
			writeAtlas(writer, file.FullName);
			npack++;
		}
		// write num of pack
		long realSeek = writer.BaseStream.Position;
		writer.BaseStream.Position = 0;
		writer.WriteInt16BE((short)npack);
		writer.BaseStream.Position = realSeek;
		write2Bin(stream, NAME_ATLAS_OUT_PUT);
	}

        static public void log(string str)
        {
            Console.WriteLine(str);
        }
        

        static public void writeAtlas(WagBinaryWriter writer, string filePath)
        {
            string[] filenames = filePath.Split('\\');
            string filename = filenames[filenames.Length - 1];
            System.Xml.Linq.XElement booksFromFile = System.Xml.Linq.XElement.Load(@filePath);
            //Console.WriteLine(booksFromFile);
            IEnumerable<XElement> tests = from el in booksFromFile.Elements() select el;
            short count = 0;
            foreach (XElement el1 in tests)
                count++;

            writer.Write(filename);
            writer.WriteInt16BE((short)count);
            foreach (XElement el in tests)
            {
                //Console.WriteLine((string)el.Attribute("name"));
                writer.Write((string)el.Attribute("name"));
                writer.WriteInt16BE((short)el.Attribute("x"));
                writer.WriteInt16BE((short)el.Attribute("y"));
                writer.WriteInt16BE((short)el.Attribute("width"));
                writer.WriteInt16BE((short)el.Attribute("height"));
                //frame
                if ((string)el.Attribute("frameX") != null)
                    writer.WriteInt16BE((short)el.Attribute("frameX"));
                else
                    writer.WriteInt16BE((short)0);

                if ((string)el.Attribute("frameY") != null)
                    writer.WriteInt16BE((short)el.Attribute("frameY"));
                else
                    writer.WriteInt16BE((short)0);

                if ((string)el.Attribute("frameWidth") != null)
                    writer.WriteInt16BE((short)el.Attribute("frameWidth"));
                else
                    writer.WriteInt16BE((short)0);

                if ((string)el.Attribute("frameHeight") != null)
                    writer.WriteInt16BE((short)el.Attribute("frameHeight"));
                else
                    writer.WriteInt16BE((short)0);
            }
        }

	static public void buildFonts()
	{
		Console.WriteLine("============= FONT ==================");
		MemoryStream stream = new MemoryStream();
		WagBinaryWriter writer = new WagBinaryWriter(stream);
		DirectoryInfo d = new DirectoryInfo(Directory.GetCurrentDirectory());
		foreach (var file in d.GetFiles("*.fnt"))
		{
			log(file.FullName);
			writeFont(writer, file.FullName);
			break;
		}
		write2Bin(stream, NAME_FONT_OUT_PUT);
	}

	static public void writeFont(WagBinaryWriter writer, string filePath)
        {
            string[] filenames = filePath.Split('\\');
            string filename = filenames[filenames.Length - 1];
            System.Xml.Linq.XElement booksFromFile = System.Xml.Linq.XElement.Load(@filePath);
			booksFromFile =  booksFromFile.Element("chars");
            IEnumerable<XElement> tests = from el in booksFromFile.Elements() select el;
            short count = 0;
            foreach (XElement el1 in tests)
                count++;

            writer.WriteInt16BE((short)count);
            foreach (XElement el in tests)
            {
					//Console.WriteLine((string)el.Attribute("name"));
					writer.WriteInt16BE((short)el.Attribute("x"));
					writer.WriteInt16BE((short)el.Attribute("y"));
					writer.Write(short_to_byte((short)el.Attribute("width")));
					writer.Write(short_to_byte((short)el.Attribute("height")));
					writer.Write(short_to_byte((short)el.Attribute("xoffset")));
					writer.Write(short_to_byte((short)el.Attribute("yoffset")));
					writer.WriteInt16BE((short)el.Attribute("id"));
					writer.Write(short_to_byte((short)el.Attribute("xadvance")));
            }
        }

	public static byte short_to_byte(short value)
	{
		byte[] bytes = BitConverter.GetBytes(value);
		return bytes[0];

	}

        public static void write2Bin(MemoryStream stream, string filename)
        {
            try
            {
                // else create a new one.
		FileInfo fileInfo = new FileInfo(filename);
                FileStream fileStream = fileInfo.Open(FileMode.Create,
                    FileAccess.Write);
                byte[] bytes = stream.GetBuffer();
                fileStream.Write(bytes, 0, bytes.Length);
                fileStream.Flush();
                fileStream.Close();
            }
            catch (IOException ioe)
            {
                Console.WriteLine(ioe);
            }
        }

    }
}
