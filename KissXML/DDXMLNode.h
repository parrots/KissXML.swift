#import <Foundation/Foundation.h>

@class DDXMLDocument, DDXMLElement;

/**
 * Welcome to KissXML.
 * 
 * The project page has documentation if you have questions.
 * https://github.com/robbiehanson/KissXML
 * 
 * If you're new to the project you may wish to read the "Getting Started" wiki.
 * https://github.com/robbiehanson/KissXML/wiki/GettingStarted
 * 
 * KissXML provides a drop-in replacement for Apple's NSXML class cluster.
 * The goal is to get the exact same behavior as the NSXML classes.
 * 
 * For API Reference, see Apple's excellent documentation,
 * either via Xcode's Mac OS X documentation, or via the web:
 * 
 * https://github.com/robbiehanson/KissXML/wiki/Reference
**/

typedef NS_OPTIONS(NSUInteger, DDXMLNodeOptions) {
    DDXMLNodeOptionsNone            = 0,
    DDXMLNodeExpandEmptyElement     = 1 << 1,
    DDXMLNodeCompactEmptyElement    = 1 << 2,
    DDXMLNodePrettyPrint            = 1 << 17,
};


//extern struct _xmlKind;


@interface DDXMLNode : NSObject <NSCopying>
{
	// Every DDXML object is simply a wrapper around an underlying libxml node
	struct _xmlKind *genericPtr;
	
	// Every libxml node resides somewhere within an xml tree heirarchy.
	// We cannot free the tree heirarchy until all referencing nodes have been released.
	// So all nodes retain a reference to the node that created them,
	// and when the last reference is released the tree gets freed.
	DDXMLNode *owner;
}

//- (id)initWithKind:(DDXMLNodeKind)kind;
//- (id)initWithKind:(DDXMLNodeKind)kind options:(NSUInteger)options;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

+ (DDXMLElement *)elementWithName:(NSString *)name;
+ (DDXMLElement *)elementWithName:(NSString *)name URI:(NSString *)URI;
+ (DDXMLElement *)elementWithName:(NSString *)name stringValue:(NSString *)string;
+ (DDXMLElement *)elementWithName:(NSString *)name children:(NSArray *)children attributes:(NSArray *)attributes;

+ (DDXMLNode *)attributeWithName:(NSString *)name stringValue:(NSString *)stringValue;
+ (DDXMLNode *)attributeWithName:(NSString *)name URI:(NSString *)URI stringValue:(NSString *)stringValue;
+ (DDXMLNode *)namespaceWithName:(NSString *)name stringValue:(NSString *)stringValue;
+ (DDXMLNode *)processingInstructionWithName:(NSString *)name stringValue:(NSString *)stringValue;
+ (DDXMLNode *)commentWithStringValue:(NSString *)stringValue;
+ (DDXMLNode *)textWithStringValue:(NSString *)stringValue;

//+ (id)DTDNodeWithXMLString:(NSString *)string;

#pragma mark --- Properties ---

@property (nonatomic, strong) NSString *name;

//- (void)setObjectValue:(id)value;
//- (id)objectValue;

@property (nonatomic, strong) NSString *stringValue;
//- (void)setStringValue:(NSString *)string resolvingEntities:(BOOL)resolve;

#pragma mark --- Tree Navigation ---

@property (nonatomic, readonly) NSUInteger index;
@property (nonatomic, readonly) NSUInteger level;
@property (nonatomic, readonly) DDXMLDocument *rootDocument;

@property (nonatomic, readonly) DDXMLNode *parent;
@property (nonatomic, readonly) NSUInteger childCount;
@property (nonatomic, readonly) NSArray *children;
- (DDXMLNode *)childAtIndex:(NSUInteger)index;

@property (nonatomic, readonly) DDXMLNode *previousSibling;
@property (nonatomic, readonly) DDXMLNode *nextSibling;

@property (nonatomic, readonly) DDXMLNode *previousNode;
@property (nonatomic, readonly) DDXMLNode *nextNode;

- (void)detach;

@property (nonatomic, readonly) NSString *XPath;

#pragma mark --- QNames ---

@property (nonatomic, readonly) NSString *localName;
@property (nonatomic, readonly) NSString *prefix;

@property (nonatomic, strong) NSString *URI;

+ (NSString *)localNameForName:(NSString *)name;
+ (NSString *)prefixForName:(NSString *)name;
//+ (DDXMLNode *)predefinedNamespaceForPrefix:(NSString *)name;

#pragma mark --- Output ---

@property (nonatomic, readonly) NSString *XMLString;
- (NSString *)XMLStringWithOptions:(DDXMLNodeOptions)options;
//- (NSString *)canonicalXMLStringPreservingComments:(BOOL)comments;

#pragma mark --- XPath/XQuery ---

- (NSArray *)nodesForXPath:(NSString *)xpath error:(NSError **)error;
//- (NSArray *)objectsForXQuery:(NSString *)xquery constants:(NSDictionary *)constants error:(NSError **)error;
//- (NSArray *)objectsForXQuery:(NSString *)xquery error:(NSError **)error;

@end
