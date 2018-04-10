class Codec:
	
	import string
	letters = string.ascii_letters + string.digits
	full_tiny = {}
	tiny_full = {}
	global_c = 0
	
	def encode(self, longUrl):
		"""Encodes a URL to a shortened URL.
		
		:type longUrl: str
		:rtype: str
		"""
		def decto62(dec):
			ans = ""
			while 1 :
				ans = self.letters[dec%62] + ans
				dec //= 62
				if not dec:
					break
#			print()
			return ans;
		suffix  = decto62(self.global_c)
		if longUrl not in self.full_tiny:
			self.full_tiny[longUrl] = suffix
			self.tiny_full[suffix] = longUrl
			self.global_c += 1
		return "http://tinyurl.com/" + suffix

	def decode(self, shortUrl):
		"""Decodes a shortened URL to its original URL.
		
		:type shortUrl: str
		:rtype: str
		"""
		id = shortUrl.split('/')[-1]
#		print("")
		if id in self.tiny_full:
			return self.tiny_full[id]
		else:
			return None

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))