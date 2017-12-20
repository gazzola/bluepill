//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, XCUITestContextScope;

@interface XCUITestContext : NSObject
{
    _Bool _didHandleUIInterruption;
    XCUITestContextScope *_currentScope;
}

+ (CDUnknownBlockType)defaultAsynchronousUIElementHandler;
@property _Bool didHandleUIInterruption; // @synthesize didHandleUIInterruption=_didHandleUIInterruption;
@property(retain, nonatomic) XCUITestContextScope *currentScope; // @synthesize currentScope=_currentScope;
- (_Bool)handleAsynchronousUIElement:(id)arg1;
- (void)removeUIInterruptionMonitor:(id)arg1;
- (id)addUIInterruptionMonitorWithDescription:(id)arg1 handler:(CDUnknownBlockType)arg2;
- (void)performInScope:(CDUnknownBlockType)arg1;
@property(readonly, copy) NSArray *handlers;
- (id)init;
- (void)dealloc;

@end
