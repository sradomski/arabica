#ifndef test_hc_attrappendchild3
#define test_hc_attrappendchild3


/*
This C++ source file was generated for Arabica
from the source document contained in the W3C
DOM Conformance Test Suite.
The source document contained the following notice:


Copyright (c) 2001-2004 World Wide Web Consortium,
(Massachusetts Institute of Technology, Institut National de
Recherche en Informatique et en Automatique, Keio University). All
Rights Reserved. This program is distributed under the W3C's Software
Intellectual Property License. This program is distributed in the
hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.
See W3C License http://www.w3.org/Consortium/Legal/ for more details.

*/
/**
 * Appends a document fragment to an attribute and checks if the value of
 * the attribute is changed.
* @author Curt Arnold
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-637646024">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-637646024</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-184E7107">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-184E7107</a>
*/

template<class string_type, class string_adaptor>
class hc_attrappendchild3 : public DOMTestCase<string_type, string_adaptor> 
{
    typedef DOMTestCase<string_type, string_adaptor> baseT;
   public: 
     hc_attrappendchild3(std::string name) : baseT(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = baseT::getContentType();
    baseT::preload(contentType, "hc_staff", true);
    }

  typedef typename Arabica::DOM::DOMImplementation<string_type, string_adaptor>  DOMImplementation;
  typedef typename Arabica::DOM::Document<string_type, string_adaptor> Document; 
  typedef typename Arabica::DOM::DocumentType<string_type, string_adaptor> DocumentType;
  typedef typename Arabica::DOM::DocumentFragment<string_type, string_adaptor> DocumentFragment; 
  typedef typename Arabica::DOM::Node<string_type, string_adaptor> Node;
  typedef typename Arabica::DOM::Element<string_type, string_adaptor> Element;
  typedef typename Arabica::DOM::Attr<string_type, string_adaptor> Attr;
  typedef typename Arabica::DOM::NodeList<string_type, string_adaptor> NodeList;
  typedef typename Arabica::DOM::NamedNodeMap<string_type, string_adaptor> NamedNodeMap;
  typedef typename Arabica::DOM::Entity<string_type, string_adaptor> Entity;
  typedef typename Arabica::DOM::EntityReference<string_type, string_adaptor> EntityReference;
  typedef typename Arabica::DOM::CharacterData<string_type, string_adaptor> CharacterData;
  typedef typename Arabica::DOM::CDATASection<string_type, string_adaptor> CDATASection;
  typedef typename Arabica::DOM::Text<string_type, string_adaptor> Text;
  typedef typename Arabica::DOM::Comment<string_type, string_adaptor> Comment;
  typedef typename Arabica::DOM::ProcessingInstruction<string_type, string_adaptor> ProcessingInstruction;
  typedef typename Arabica::DOM::Notation<string_type, string_adaptor> Notation;

  typedef typename Arabica::DOM::DOMException DOMException;
  typedef string_type String;
  typedef string_adaptor SA;
  typedef bool boolean;


   /*
    * Runs the test case.
    */
   void runTest()
   {
      Document doc;
      NodeList acronymList;
      Node testNode;
      NamedNodeMap attributes;
      Attr titleAttr;
      String value;
      Text terNode;
      Text dayNode;
      Node retval;
      Node lastChild;
      DocumentFragment docFrag;
      doc = (Document) baseT::load("hc_staff", true);
      acronymList = doc.getElementsByTagName(SA::construct_from_utf8("acronym"));
      testNode = acronymList.item(3);
      attributes = testNode.getAttributes();
      titleAttr = (Attr) attributes.getNamedItem(SA::construct_from_utf8("title"));
      terNode = doc.createTextNode(SA::construct_from_utf8("ter"));
      dayNode = doc.createTextNode(SA::construct_from_utf8("day"));
      docFrag = doc.createDocumentFragment();
      retval = docFrag.appendChild(terNode);
      retval = docFrag.appendChild(dayNode);
      retval = titleAttr.appendChild(docFrag);
      value = titleAttr.getValue();
      baseT::assertEquals("Yesterday", value, __LINE__, __FILE__);
  value = titleAttr.getNodeValue();
      baseT::assertEquals("Yesterday", value, __LINE__, __FILE__);
  value = retval.getNodeValue();
      baseT::assertNull(value, __LINE__, __FILE__);
      lastChild = titleAttr.getLastChild();
      value = lastChild.getNodeValue();
      baseT::assertEquals("day", value, __LINE__, __FILE__);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/hc_attrappendchild3";
   }
};

#endif
