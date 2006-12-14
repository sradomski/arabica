#ifndef test_TREEWALKER_HPP
#define test_TREEWALKER_HPP

#include "../CppUnit/framework/TestCase.h"
#include "../CppUnit/framework/TestSuite.h"
#include "../CppUnit/framework/TestCaller.h"
#include <sstream>
#include <DOM/SAX2DOM/SAX2DOM.h>
#include <SAX/helpers/CatchErrorHandler.h>

template<class string_type, class string_adaptor>
class TreeWalkerTest : public TestCase 
{
  typedef string_adaptor SA;

  public: 
    TreeWalkerTest(std::string name) :
        TestCase(name) 
    {
    } // TreeWalkerTest
    
    void setUp() 
    {
    } // setUp

    DOM::Document<string_type> parse(string_type str)
    {
      std::stringstream ss;
      ss << SA::asStdString(str);

      SAX::basic_InputSource<string_type> is(ss);
      SAX::CatchErrorHandler<string_type> eh;
      SAX2DOM::Parser<string_type, string_adaptor> parser;
      parser.setErrorHandler(eh);
      parser.parse(is);       

      //if(eh.errorsReported())
      //  throw std::runtime_error(eh.errors());

      return parser.getDocument();
    } // parse

    void test1()
    {
      DOM::Document<string_type> d = parse(SA::construct_from_utf8("<root/>"));
      DOM::Element<string_type> elem = d.getDocumentElement();

      DOM::Traversal::DocumentTraversal<string_type> traversal = d.createDocumentTraversal();
      DOM::Traversal::TreeWalker<string_type> walker = traversal.createTreeWalker(d.getDocumentElement(),
                                                                                  DOM::Traversal::SHOW_ALL,
                                                                                  true);
      assert(walker.getWhatToShow() == DOM::Traversal::SHOW_ALL);
      assert(walker.getFilter() == 0);
      assert(walker.getCurrentNode() == elem);
      assert(walker.nextNode() == 0);
    } // test1

    void test2()
    {
      DOM::Document<string_type> d = parse(SA::construct_from_utf8("<root><parp/><poop/></root>"));
      DOM::Element<string_type> elem = d.getDocumentElement();

      DOM::Traversal::DocumentTraversal<string_type> traversal = d.createDocumentTraversal();
      DOM::Traversal::TreeWalker<string_type> walker = traversal.createTreeWalker(d.getDocumentElement(),
                                                                                  DOM::Traversal::SHOW_ALL,
                                                                                  true);
      assert(walker.getCurrentNode() == elem);
      assert(walker.nextNode() == elem.getFirstChild());
      assert(walker.nextNode() == elem.getLastChild());
      assert(walker.nextNode() == 0);
    } // test2

    void test3()
    {
      DOM::Document<string_type> d = parse(SA::construct_from_utf8("<root><parp>hello</parp><poop>mother</poop></root>"));
      DOM::Element<string_type> elem = d.getDocumentElement();

      DOM::Traversal::DocumentTraversal<string_type> traversal = d.createDocumentTraversal();
      DOM::Traversal::TreeWalker<string_type> walker = traversal.createTreeWalker(d.getDocumentElement(),
                                                                                  DOM::Traversal::SHOW_ALL,
                                                                                  true);
      assert(walker.getCurrentNode() == elem);
      assert(walker.nextNode() == elem.getFirstChild());
      assert(walker.nextNode() == elem.getFirstChild().getFirstChild());
      assert(walker.nextNode() == elem.getLastChild());
      assert(walker.nextNode() == elem.getLastChild().getFirstChild());
      assert(walker.nextNode() == 0);
    } // test3

    void test4()
    {
      DOM::Document<string_type> d = parse(SA::construct_from_utf8("<root><parp>hello</parp><poop>mother</poop></root>"));
      DOM::Element<string_type> elem = d.getDocumentElement();

      DOM::Traversal::DocumentTraversal<string_type> traversal = d.createDocumentTraversal();
      DOM::Traversal::TreeWalker<string_type> walker = traversal.createTreeWalker(d.getDocumentElement(),
                                                                                  DOM::Traversal::SHOW_ELEMENT,
                                                                                  true);
      assert(walker.getCurrentNode() == elem);
      assert(walker.nextNode() == elem.getFirstChild());
      assert(walker.nextNode() == elem.getLastChild());
      assert(walker.nextNode() == 0);
    } // test4

    void test5()
    {
      DOM::Document<string_type> d = parse(SA::construct_from_utf8("<root><parp>hello</parp><poop>mother</poop></root>"));
      DOM::Element<string_type> elem = d.getDocumentElement();

      DOM::Traversal::DocumentTraversal<string_type> traversal = d.createDocumentTraversal();
      DOM::Traversal::TreeWalker<string_type> walker = traversal.createTreeWalker(d.getDocumentElement(),
                                                                                  DOM::Traversal::SHOW_TEXT,
                                                                                  true);
      assert(walker.getCurrentNode() == elem);
      assert(walker.nextNode() == elem.getFirstChild().getFirstChild());
      assert(walker.nextNode() == elem.getLastChild().getFirstChild());
      assert(walker.nextNode() == 0);
    } // test5

    void test6()
    {
      DOM::Document<string_type> d = parse(SA::construct_from_utf8("<root id='0'><parp>hello</parp><poop>mother</poop></root>"));
      DOM::Element<string_type> elem = d.getDocumentElement();

      DOM::Traversal::DocumentTraversal<string_type> traversal = d.createDocumentTraversal();
      DOM::Traversal::TreeWalker<string_type> walker = traversal.createTreeWalker(d.getDocumentElement(),
                                                                                  DOM::Traversal::SHOW_ALL,
                                                                                  true);
      assert(walker.getCurrentNode() == elem);
      assert(walker.nextNode() == elem.getFirstChild());
      assert(walker.nextNode() == elem.getFirstChild().getFirstChild());
      assert(walker.nextNode() == elem.getLastChild());
      assert(walker.nextNode() == elem.getLastChild().getFirstChild());
      assert(walker.nextNode() == 0);
    } // test6
};

template<class string_type, class string_adaptor>
TestSuite* TreeWalkerTest_suite() 
{
  TestSuite *suiteOfTests = new TestSuite;
  suiteOfTests->addTest(new TestCaller<TreeWalkerTest<string_type, string_adaptor> >("test1", &TreeWalkerTest<string_type, string_adaptor>::test1));
  suiteOfTests->addTest(new TestCaller<TreeWalkerTest<string_type, string_adaptor> >("test2", &TreeWalkerTest<string_type, string_adaptor>::test2));
  suiteOfTests->addTest(new TestCaller<TreeWalkerTest<string_type, string_adaptor> >("test3", &TreeWalkerTest<string_type, string_adaptor>::test3));
  suiteOfTests->addTest(new TestCaller<TreeWalkerTest<string_type, string_adaptor> >("test4", &TreeWalkerTest<string_type, string_adaptor>::test4));
  suiteOfTests->addTest(new TestCaller<TreeWalkerTest<string_type, string_adaptor> >("test5", &TreeWalkerTest<string_type, string_adaptor>::test5));
  suiteOfTests->addTest(new TestCaller<TreeWalkerTest<string_type, string_adaptor> >("test6", &TreeWalkerTest<string_type, string_adaptor>::test6));
  return suiteOfTests;
} // TreeWalkerTest_suite

#endif

