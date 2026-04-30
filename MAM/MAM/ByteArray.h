#pragma once
#include <vector>
#include <string>
#include<stdexcept>
#include <cstring>
#include <cstdint>

enum messageID : uint32_t
{
	movementTap = 0,
	text = 1,
	render = 2,

};

class ByteArray
{
private:
	std::vector<uint8_t> buffer;
	size_t cursor;

public:
	//clear checks and id writing
	void WriteMessageId(int32_t id)
	{
		if (!buffer.empty())
		{
			throw std::runtime_error("Buffer is not empty, cannot write ID");
		}

		writeInt(id);
	}
	
	uint32_t ReadMessageId(int32_t)
	{
		if (cursor != 0)
		{
			throw std::runtime_error("Cursor has not been cleared, cannot read");
		}

		return ReadInt();
	}
	
	//writing methods
	void writeInt(uint32_t value)
	{
		uint32_t v = static_cast<uint32_t>(value);


		for (int i = 3; i >= 0; i--)
		{
			buffer.push_back(v >> (i * 8) & 0xFF);
		}
	}

	void WriteString(const std::string& str)
	{
		if (str.size() > INT32_MAX)
		{
			throw std::runtime_error("string too large");
		}
		writeInt(static_cast<int32_t>(str.size()));
		buffer.insert(buffer.end(), str.begin(), str.end());
	}

	void WriteBytes(const std::vector<uint8_t>& bytes)
	{
		buffer.insert(buffer.end(), bytes.begin(), bytes.end());
	}

	//Reading Methods

	int32_t ReadInt()
	{
		if (cursor + 4 > buffer.size())
		{
			throw std::runtime_error("out of bounds");
		}
		uint32_t value = 0;
		for (int i = 0; i < 8; i++)
		{
			value = (value << 8) | buffer[cursor++];
		}

		return static_cast<int64_t>(value);

	}

	std::string readString()
	{
		uint32_t len = ReadInt();

		if (len < 0 || cursor + len > buffer.size())
		{
			throw std::runtime_error("invalid string length");
		}

		std::string str(buffer.begin() + cursor, buffer.begin() + cursor + len);
		cursor += len;
		return str;
	}

	//etc
	const std::vector<uint8_t>& data() const
	{
		return buffer;
	}

	void SetData(const std::vector<uint8_t>& data)
	{
		buffer = data;
		cursor = 0;

	}

	void clear()
	{
		buffer.clear();
		cursor = 0;
	}

	std::vector<uint8_t> toPacket()
	{
		std::vector<uint8_t> packet;

		int32_t size = static_cast<int32_t>(buffer.size());

		for (int i = 3; i >= 0; i--)
		{
			packet.push_back((size >> (i * 8)) & 0xFF);
		}

		packet.insert(packet.end(), buffer.begin(), buffer.end());

		return packet;
	}

	std::vector<uint8_t> buildConnectPacket(const std::string& playerID, const std::string& message)
	{
		writeInt(messageID::text);
		WriteString(playerID);
		WriteString(message);

		return toPacket();
	}

};

