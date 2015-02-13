//
//  OpenWebRTCNativeHandler.h
//
//  Copyright (c) 2015, Ericsson AB.
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without modification,
//  are permitted provided that the following conditions are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this
//  list of conditions and the following disclaimer.
//
//  2. Redistributions in binary form must reproduce the above copyright notice, this
//  list of conditions and the following disclaimer in the documentation and/or other
//  materials provided with the distribution.

//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
//  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
//  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
//  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
//  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
//  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
//  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
//  OF SUCH DAMAGE.
//

#import <Foundation/Foundation.h>
#import "OpenWebRTCVideoView.h"

#include <owr/owr_local.h>
#include <owr/owr_transport_agent.h>

@protocol OpenWebRTCNativeHandlerDelegate <NSObject>

- (void)answerGenerated:(NSString *)answer;

- (void)addHelperServersForTransportAgent:(OwrTransportAgent *)transport_agent;

@end

@interface OpenWebRTCNativeHandler : NSObject

@property (nonatomic, weak) id <OpenWebRTCNativeHandlerDelegate> delegate;

- (instancetype)init;

- (void)setSelfView:(OpenWebRTCVideoView *)selfView;
- (void)setRemoteView:(OpenWebRTCVideoView *)remoteView;

- (void)startGetCaptureSources:(OwrMediaType)types;

- (void)handleOfferReceived:(NSString *)offer;
- (void)handleRemoteCandidateReceived:(NSString *)candidate;

@end