/***

Copyright 2014 Dave Cridland
Copyright 2014 Surevine Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

***/

#ifndef SPIFFING_LABEL_H
#define SPIFFING_LABEL_H

#include <string>
#include <spiffing/constants.h>
#include <spiffing/categoryref.h>
#include <memory>
#include <set>

namespace Spiffing {
	class Label {
	public:
		Label(Spif const & spif, std::string const & label, Format fmt);
		void parse(std::string const & label, Format fmt);
		void write(Format fmt, std::string & output);

		std::shared_ptr<Classification> const & classification() const {
			return m_class;
		}
		std::string const & policy_id() const {
			return m_policy_id;
		}
		std::set<CategoryRef> const & categories() const {
			return m_cats;
		}
		Spif const & policy() const {
			return m_policy;
		}

		void addCategory(std::shared_ptr<Category> const & cat);
	private:
		void parse_ber(std::string const & label);
		void parse_xml(std::string const & label);
		void parse_any(std::string const & label);

		void write_ber(std::string &);
		void write_xml(std::string &);

		Spif const & m_policy;
		std::string m_policy_id;
		std::shared_ptr<Classification> m_class;
		std::set<CategoryRef> m_cats;
	};
}

#endif
