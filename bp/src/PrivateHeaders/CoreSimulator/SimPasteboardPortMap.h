//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@import Foundation;
@class NSMutableDictionary, NSObject;

@interface SimPasteboardPortMap : NSObject
{
    NSMutableDictionary *_portToProxyMap;
    NSObject *_concurrentQueue;
}

+ (id)sharedManager;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *concurrentQueue; // @synthesize concurrentQueue=_concurrentQueue;
@property(retain, nonatomic) NSMutableDictionary *portToProxyMap; // @synthesize portToProxyMap=_portToProxyMap;
- (id)createPortKey:(unsigned int)arg1;
- (void)setValue:(id)arg1 forPort:(unsigned int)arg2;
- (id)lookupWith:(unsigned int)arg1;
- (id)description;
- (id)init;

@end

