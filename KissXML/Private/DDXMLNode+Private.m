//
//  DDXMLNode+Private.m
//  KissXML
//
//  Created by Oliver Letterer on 19.10.14.
//  Copyright (c) 2014 Sparrow-Labs. All rights reserved.
//

#import "DDXMLNode+Private.h"
#import <DDXMLPrivate.h>

@implementation DDXMLNode (Private)

- (DDXMLNodeKind)kind
{
#if DDXML_DEBUG_MEMORY_ISSUES
    DDXMLNotZombieAssert();
#endif

    if (genericPtr != NULL) {
        return genericPtr->type;
    } else {
        return DDXMLInvalidKind;
    }
}

@end
