#ifndef test_hc_characterdatareplacedataend
#define test_hc_characterdatareplacedataend


/*
This c++ source file was generated by for Arabica
and is a derived work from the source document.
The source document contained the following notice:


Copyright (c) 2001 World Wide Web Consortium,
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
 *     The "replaceData(offset,count,arg)" method replaces the 
 *    characters starting at the specified offset with the
 *    specified string.  Test for replacement at the 
 *    end of the data.
 *    
 *    Retrieve the character data from the last child of the
 *    first employee.  The "replaceData(offset,count,arg)"
 *    method is then called with offset=30 and count=5 and
 *    arg="98665".  The method should replace characters 30  
 *    thru 34 of the character data with "98665".
* @author Curt Arnold
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-72AB8359">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-72AB8359</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-E5CBA7FB">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-E5CBA7FB</a>
*/

template<class string_type, class string_adaptor>
class hc_characterdatareplacedataend : public DOMTestCase<string_type, string_adaptor> 
{
    typedef DOMTestCase<string_type, string_adaptor> baseT;
   public: 
     hc_characterdatareplacedataend(std::string name) : baseT(name)
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
      NodeList elementList;
      Node nameNode;
      CharacterData child;
      String childData;
      doc = (Document) baseT::load("hc_staff", true);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("acronym"));
      nameNode = elementList.item(0);
      child = (CharacterData) nameNode.getFirstChild();
      child.replaceData(30, 5, SA::construct_from_utf8("98665"));
      childData = child.getData();
      baseT::assertEquals("1230 North Ave. Dallas, Texas 98665", childData);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/hc_characterdatareplacedataend";
   }
};

#endif
