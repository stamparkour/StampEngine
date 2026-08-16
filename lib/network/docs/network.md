
design
- multiple data channels
- muxer
- coroutine/callback based
- system to subscribe to certain muxer schemes.
- can work with file streams, and network streams


static muxer tokens (universal)
- ping
- negotiate dynamic tokens
dynamic muxer tokens (version dependent)
- identity verification (password)
- encryption
- connection info (client, server, DNS-ish)
- manage channels
- resume/stop connections


# negotiate dynamic tokens

any token can have sub-tokens (sub-muxers)

specify
- who decides what tokens (client or server)
- ID of the token (name and version)

modify muxer state
- add/remove child nodes of current muxer node (negotiated)
