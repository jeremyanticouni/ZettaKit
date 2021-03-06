//
//  ZIKStream.h
//  ZettaKit
//
//  Created by Matthew Dobson on 4/7/15.
//  Copyright (c) 2015 Apigee and Contributors <matt@apigee.com>
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import "ZIKLink.h"
#import <SocketRocket/SRWebSocket.h>
#import <ReactiveCocoa/ReactiveCocoa.h>

/**
 The `ZIKStream` class is responsible for connecting to different Zetta websocket streams and giving real time access to data from the Zetta HTTP API.
 */

@interface ZIKStream : NSObject<SRWebSocketDelegate>

/**
 The human readable name of the stream.
 */
@property (nonatomic, retain, readonly) NSString *title;

/**
 The ReactiveCocoa signal needed to subscribe to updates from the stream.
 */
@property (nonatomic, retain, readonly) RACSignal *signal;

///---------------------------
/// @name Initialization
///---------------------------

/**
 Initializes a `ZIKStream` with the specified siren document in `NSDictionary` form.
 
 @param data The base siren document to create the stream with.
 
 @return The newly-initialized `ZIKStream` object.
 */
+ (instancetype) initWithDictionary:(NSDictionary *)data;

/**
 Initializes a `ZIKStream` with the specified siren document in `NSDictionary` form.
 
 @param data The base siren document to create the stream with.
 
 @return The newly-initialized `ZIKStream` object.
 */
- (instancetype) initWithDictionary:(NSDictionary *)data;

/**
 Initializes a `ZIKStream` with the specified siren document in `ZIKLink` form.
 
 This is the designated initializer.
 
 @param link The `ZIKLink` object to create the stream with.
 
 @return The newly-initialized `ZIKStream` object.
 */
+ (instancetype) initWithLink:(ZIKLink *)link;

/**
 Initializes a `ZIKStream` with the specified siren document in `ZIKLink` form.
 
  @param link The `ZIKLink` object to create the stream with.
 
 @return The newly-initialized `ZIKStream` object.
 */
- (id) initWithLink:(ZIKLink *)link;

///---------------------------
/// @name Stream control
///---------------------------

/**
 Begin the flow of data from the stream.
 */
- (void) resume;

/**
 End the flow of data from the stream.
 */
- (void) stop;

@end
