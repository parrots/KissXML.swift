//
//  DDXMLNode+Private.h
//  KissXML
//
//  Created by Oliver Letterer on 19.10.14.
//  Copyright (c) 2014 Sparrow-Labs. All rights reserved.
//

#import <KissXML/DDXMLNode.h>
#import <libxml/tree.h>

enum {
    DDXMLInvalidKind                = 0,
    DDXMLDocumentKind               = XML_DOCUMENT_NODE,
    DDXMLElementKind                = XML_ELEMENT_NODE,
    DDXMLAttributeKind              = XML_ATTRIBUTE_NODE,
    DDXMLNamespaceKind              = XML_NAMESPACE_DECL,
    DDXMLProcessingInstructionKind  = XML_PI_NODE,
    DDXMLCommentKind                = XML_COMMENT_NODE,
    DDXMLTextKind                   = XML_TEXT_NODE,
    DDXMLDTDKind                    = XML_DTD_NODE,
    DDXMLEntityDeclarationKind      = XML_ENTITY_DECL,
    DDXMLAttributeDeclarationKind   = XML_ATTRIBUTE_DECL,
    DDXMLElementDeclarationKind     = XML_ELEMENT_DECL,
    DDXMLNotationDeclarationKind    = XML_NOTATION_NODE
};
typedef NSUInteger DDXMLNodeKind;



@interface DDXMLNode (Private)

@property (nonatomic, readonly) DDXMLNodeKind kind;

@end
